#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/wait.h>

#define SHM_SIZE sizeof(SharedData)

typedef struct {
    int n;
    int r;
    long fact_n;
    long fact_r;
    long fact_nr;
    int ready;  // Flag to indicate data is ready
} SharedData;

// Function to calculate factorial
long factorial(int num) {
    if (num <= 1) return 1;
    return num * factorial(num - 1);
}

int main() {
    int shmid;
    key_t key = 5678;
    SharedData *shm;

    // Create shared memory segment
    if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666)) < 0) {
        perror("shmget");
        exit(1);
    }

    // Attach the segment to our data space
    if ((shm = shmat(shmid, NULL, 0)) == (SharedData *) -1) {
        perror("shmat");
        exit(1);
    }

    shm->ready = 0;  // Initialize flag

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid > 0) {  // Parent process
        // Get input from user
        printf("Enter value of n: ");
        scanf("%d", &shm->n);
        printf("Enter value of r: ");
        scanf("%d", &shm->r);

        // Validate input
        if (shm->n < shm->r) {
            printf("Error: n must be greater than or equal to r\n");
            exit(1);
        }

        shm->ready = 1;  // Signal that data is ready

        // Wait for child to complete calculations
        while (shm->ready != 2) {
            sleep(1);
        }

        // Calculate nPr and nCr
        long nPr = shm->fact_n / shm->fact_nr;
        long nCr = shm->fact_n / (shm->fact_r * shm->fact_nr);

        printf("\nResults:\n");
        printf("Factorial of n (%d!): %ld\n", shm->n, shm->fact_n);
        printf("Factorial of r (%d!): %ld\n", shm->r, shm->fact_r);
        printf("Factorial of (n-r) (%d!): %ld\n", shm->n - shm->r, shm->fact_nr);
        printf("nPr (Permutation): %ld\n", nPr);
        printf("nCr (Combination): %ld\n", nCr);

        // Detach and remove shared memory
        shmdt(shm);
        shmctl(shmid, IPC_RMID, NULL);
        wait(NULL);  // Wait for child to exit
    }
    else {  // Child process
        // Wait for parent to provide input
        while (shm->ready != 1) {
            sleep(1);
        }

        // Calculate factorials
        shm->fact_n = factorial(shm->n);
        shm->fact_r = factorial(shm->r);
        shm->fact_nr = factorial(shm->n - shm->r);

        shm->ready = 2;  // Signal calculations are done

        // Detach shared memory
        shmdt(shm);
        exit(0);
    }

    return 0;
}


///////////

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

typedef struct {
    int n;
    int r;
    long long nCr;
    long long nPr;
    int computed; // flag to indicate child has finished computation
} SharedData;

// Function to calculate factorial
long long factorial(int num) {
    long long result = 1;
    for (int i = 2; i <= num; i++)
        result *= i;
    return result;
}

int main() {
    key_t key = ftok("shmfile", 65); // create key
    int shmid = shmget(key, sizeof(SharedData), IPC_CREAT | 0666); // allocate shared memory

    if (shmid == -1) {
        perror("shmget");
        exit(1);
    }

    SharedData *data = (SharedData *) shmat(shmid, NULL, 0); // attach shared memory

    if (data == (void *) -1) {
        perror("shmat");
        exit(1);
    }

    pid_t pid = fork(); // create child process

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // Child process: compute nCr and nPr
        while (data->computed == 0) {
            sleep(1); // wait until parent writes data
        }

        int n = data->n;
        int r = data->r;

        long long factN = factorial(n);
        long long factR = factorial(r);
        long long factNR = factorial(n - r);

        data->nCr = factN / (factR * factNR);
        data->nPr = factN / factNR;

        data->computed = 2; // signal to parent that computation is done

        shmdt(data); // detach
        exit(0);
    } else {
        // Parent process: take input, wait for result
        printf("Enter n: ");
        scanf("%d", &data->n);
        printf("Enter r: ");
        scanf("%d", &data->r);
        data->computed = 1; // signal child to compute

        while (data->computed != 2) {
            sleep(1); // wait for child
        }

        printf("\nnCr (C(%d, %d)) = %lld\n", data->n, data->r, data->nCr);
        printf("nPr (P(%d, %d)) = %lld\n", data->n, data->r, data->nPr);

        shmdt(data); // detach
        shmctl(shmid, IPC_RMID, NULL); // delete shared memory
    }

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/wait.h>

// Structure for inputs
typedef struct {
    char shape[20];
    float dim1, dim2;
} ShapeInput;

int main() {
    int pipefd[2]; // pipe for parent -> child
    pid_t pid;

    // Create shared memory
    int shmid = shmget(IPC_PRIVATE, sizeof(float), IPC_CREAT | 0666);
    if (shmid < 0) {
        perror("shmget failed");
        exit(1);
    }

    if (pipe(pipefd) == -1) {
        perror("Pipe failed");
        exit(1);
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }

    else if (pid == 0) {
        // Child Process
        close(pipefd[1]); // Close write end

        ShapeInput input;
        read(pipefd[0], &input, sizeof(input));
        close(pipefd[0]);

        float area = 0;
        if (strcmp(input.shape, "circle") == 0) {
            area = 3.1416 * input.dim1 * input.dim1;
        } else if (strcmp(input.shape, "rectangle") == 0) {
            area = input.dim1 * input.dim2;
        } else if (strcmp(input.shape, "square") == 0) {
            area = input.dim1 * input.dim1;
        } else if (strcmp(input.shape, "triangle") == 0) {
            area = 0.5 * input.dim1 * input.dim2;
        }

        // Write area to shared memory
        float *shm_area = (float *)shmat(shmid, NULL, 0);
        *shm_area = area;
        shmdt(shm_area);
        exit(0);
    }

    else {
        // Parent Process
        close(pipefd[0]); // Close read end

        ShapeInput input;
        printf("Enter shape (circle, rectangle, square, triangle): ");
        scanf("%s", input.shape);
        printf("Enter dimension 1: ");
        scanf("%f", &input.dim1);
        if (strcmp(input.shape, "circle") != 0 && strcmp(input.shape, "square") != 0) {
            printf("Enter dimension 2: ");
            scanf("%f", &input.dim2);
        } else {
            input.dim2 = 0;
        }

        write(pipefd[1], &input, sizeof(input));
        close(pipefd[1]);

        wait(NULL); // Wait for child

        float *shm_area = (float *)shmat(shmid, NULL, 0);
        printf("Area of %s = %.2f\n", input.shape, *shm_area);
        shmdt(shm_area);
        shmctl(shmid, IPC_RMID, NULL); // Remove shared memory
    }

    return 0;
}

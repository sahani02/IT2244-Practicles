/*exircise02:
First child:sept for 2 second.exit with status 2.
Second child:sept for 1 second.exit with status 1.
parent:wait twise, and prints which child(by PID or exit code)
finishedfirst and second.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child1, child2, finished;
    int status;

    // Create first child
    child1 = fork();
    if (child1 == 0) {
        // First child: sleep for 2 seconds and exit with status 2
        sleep(2);
        exit(2);
    }

    // Create second child
    child2 = fork();
    if (child2 == 0) {
        // Second child: sleep for 1 second and exit with status 1
        sleep(1);
        exit(1);
    }

    // Parent process: wait twice and print which child finished first and second
    for (int i = 0; i < 2; i++) {
        finished = wait(&status);
        if (WIFEXITED(status)) {
            printf("Child with PID %d finished with exit code %d\n", finished, WEXITSTATUS(status));
        } else {
            printf("Child with PID %d terminated abnormally\n", finished);
        }
    }

    return 0;
}


/*exircise03:
First child:sept for 2 second.exit with status 2.
Second child:sept for 1 second.exit with status 1.
parent:wait twise, and prints which child(by PID or exit code)
finishedfirst and second.*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t child1, child2, finished1, finished2;
    int status1, status2;

    // Create first child
    child1 = fork();
    if (child1 == 0) {
        // First child: sleep for 2 seconds and exit with status 2
        sleep(2);
        exit(2);
    }

    // Create second child
    child2 = fork();
    if (child2 == 0) {
        // Second child: sleep for 1 second and exit with status 1
        sleep(1);
        exit(1);
    }

    // Parent: wait for first finished child
    finished1 = wait(&status1);
    // Parent: wait for second finished child
    finished2 = wait(&status2);

    // Determine and print which child finished first and second
    printf("First finished: PID = %d, Exit Code = %d\n", 
           finished1, WEXITSTATUS(status1));
    printf("Second finished: PID = %d, Exit Code = %d\n", 
           finished2, WEXITSTATUS(status2));

    return 0;
}

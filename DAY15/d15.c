/*Question:

Write a C program that performs the following tasks using process creation with fork():
Accept three integers a, b, and c from the user.
Create three child processes:
Child Process 1: Calculates and displays the factorial of a.
Child Process 2: Generates and displays the first b numbers of the Fibonacci series.
Child Process 3: Checks whether the number c is a prime number and displays the result.*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int a, b, c; // Global variables

int main() {
    // Get inputs from the user
    printf("Enter a (for factorial): ");
    scanf("%d", &a);

    printf("Enter b (for Fibonacci): ");
    scanf("%d", &b);

    printf("Enter c (for prime numbers): ");
    scanf("%d", &c);

    int pid1 = fork(); // First child
    if (pid1 == 0) {
        // Child 1: Calculate factorial of a
        int fact = 1;
        for (int i = 1; i <= a; i++) {
            fact *= i;
        }
        printf("Child 1 (Factorial): PID=%d, PPID=%d, Factorial of %d is %d\n", getpid(), getppid(), a, fact);
        exit(0);
    } else {
        int pid2 = fork(); // Second child
        if (pid2 == 0) {
            // Child 2: Fibonacci series of first b numbers
            int t1 = 0, t2 = 1, next;
            printf("Child 2 (Fibonacci): PID=%d, PPID=%d, First %d Fibonacci numbers: ", getpid(), getppid(), b);
            for (int i = 0; i < b; i++) {
                printf("%d ", t1);
                next = t1 + t2;
                t1 = t2;
                t2 = next;
            }
            printf("\n");
            exit(0);
        } else {
            int pid3 = fork(); // Third child
            if (pid3 == 0) {
                // Child 3: First c prime numbers
                int count = 0, num = 2;
                printf("Child 3 (Primes): PID=%d, PPID=%d, First %d prime numbers: ", getpid(), getppid(), c);
                while (count < c) {
                    int isPrime = 1;
                    for (int i = 2; i <= num / 2; i++) {
                        if (num % i == 0) {
                            isPrime = 0;
                            break;
                        }
                    }
                    if (isPrime) {
                        printf("%d ", num);
                        count++;
                    }
                    num++;
                }
                printf("\n");
                exit(0);
            } else {
                // Parent waits for all children
                wait(NULL);
                wait(NULL);
                wait(NULL);
                printf("Parent Process: PID=%d, All child processes completed.\n", getpid());
            }
        }
    }

    return 0;
}
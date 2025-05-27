Header Files and Global Variables

    #include <stdio.h>      // For input/output functions like printf, scanf
    #include <unistd.h>     // For fork(), getpid(), getppid()
    #include <stdlib.h>     // For exit()
    #include <sys/wait.h>   // For wait()
    
    int a, b, c; // Global variables to store user input for factorial, Fibonacci, and prime calculations
    int main() {

User Input

User is prompted to enter three integers:
a: For factorial calculation.
b: Number of Fibonacci numbers.
c: Number of prime numbers.

    // Get inputs from the user
    printf("Enter a (for factorial): ");
    scanf("%d", &a);

    printf("Enter b (for Fibonacci): ");
    scanf("%d", &b);

    printf("Enter c (for prime numbers): ");
    scanf("%d", &c);

First Child Process - Factorial

    int pid1 = fork(); // First child
    
Creates a new process (pid1) using fork().

    if (pid1 == 0) {//This condition is true only in the child process.
        // Child 1: Calculate factorial of a
        int fact = 1;
        for (int i = 1; i <= a; i++) {
            fact *= i;
        }
        
Factorial of a is calculated using a for loop.

        printf("Child 1 (Factorial): PID=%d, PPID=%d, Factorial of %d is %d\n", getpid(), getppid(), a, fact);

The child prints its own process ID (PID), parent’s PID (PPID), and the result.

        exit(0);//Exits the child process after its work is done.

Second Child Process - Fibonacci

    } else {
        int pid2 = fork(); // Second child
        if (pid2 == 0) {
        
The parent continues and creates a second child.
Inside this block, the second child process begins.

            // Child 2: Fibonacci series of first b numbers
            int t1 = 0, t2 = 1, next;
            printf("Child 2 (Fibonacci): PID=%d, PPID=%d, First %d Fibonacci numbers: ", getpid(), getppid(), b);

Initializes first two Fibonacci numbers and prints header.

            for (int i = 0; i < b; i++) {
                printf("%d ", t1);
                next = t1 + t2;
                t1 = t2;
                t2 = next;
            }
            printf("\n");
Loops b times to print the Fibonacci series.

            exit(0);//Exits the second child after completion.

Third Child Process - Prime Numbers
        } else {
            int pid3 = fork(); // Third child
            if (pid3 == 0) {
            
The parent of the first two children creates the third child.
                // Child 3: First c prime numbers
                int count = 0, num = 2;
                printf("Child 3 (Primes): PID=%d, PPID=%d, First %d prime numbers: ", getpid(), getppid(), c);

Initializes values for checking primes.

                while (count < c) {
                    int isPrime = 1;
                    for (int i = 2; i <= num / 2; i++) {
                        if (num % i == 0) {
                            isPrime = 0;
                            break;
                        }
                    }
Loops to find and print first c prime numbers.

                    if (isPrime) {
                        printf("%d ", num);
                        count++;
                    }
                    num++;
                }
                printf("\n");
                exit(0);//Prints primes and exits.

Parent Process

            } else {
                // Parent waits for all children
                wait(NULL);
                wait(NULL);
                wait(NULL);
                printf("Parent Process: PID=%d, All child processes completed.\n", getpid());
            }
        }
    }
    
The original parent process waits (wait(NULL)) for all 3 child processes to complete.
Finally, it prints a message indicating completion.
Program End

    return 0;
    }


![Screenshot 2025-05-27 233710](https://github.com/user-attachments/assets/9ed5262f-644e-4171-92a5-8cf26fe0e40c)

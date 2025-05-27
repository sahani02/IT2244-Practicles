This C program demonstrates process creation and hierarchy using the fork() system call. It performs multiple mathematical computations such as:

1.Factorial

2.Fibonacci

3.Power of 2

4.Square of a number


✅ Key Concepts Used:


fork() – Creates a new process (child).

getpid() / getppid() – Prints process ID and parent process ID.

wait() – Ensures the parent waits for child processes to complete.

Hierarchical child process creation – One of the child processes creates its own child (grandchild to the original parent).


🧠 How it works:

The main (parent) process creates:


Child1, which calculates factorial and creates Child5 to compute the nth Fibonacci number.

Child2, which calculates 2ⁿ.

Child3, which calculates the square of n.


Parent waits for all its direct children to finish before exiting.

This program is an example of multi-process computation using process trees, commonly studied in Operating Systems.

![Screenshot 2025-05-27 235748](https://github.com/user-attachments/assets/c10dbed1-57ed-494e-a391-a37b410b7023)

new4.c file output

Key Points:
- Prints a start message.
- Uses sleep(3) to pause execution for 3 seconds.
- Prints a message before exiting.
- Exits cleanly using exit(0).
- Demonstrates basic program flow with sleep and exit.

![Screenshot 2025-05-29 221836](https://github.com/user-attachments/assets/e2c28c6f-2e38-45b1-a604-fb560fd3c6eb)

Key Points:
- The program creates one child process using fork().
- The child process sleeps for 2 seconds, then exits with status 0.
- The parent process waits for the child to finish using wait(&status).
- The parent checks if the child exited normally using WIFEXITED(status).
- If normal, it prints the child's exit status using WEXITSTATUS(status).
- Demonstrates process creation, child sleeping, waiting, and exit status retrieval.

![Screenshot 2025-05-29 222043](https://github.com/user-attachments/assets/4b16afc9-cd93-448d-ae14-fd7549a805b9)

new6.c file output

Key Points:
- Creates two child processes using fork().
- First child sleeps for 1 second, then exits.
- Second child sleeps for 3 seconds, then exits.
- Parent process waits for both children using wait().
- After both children exit, the parent prints a message.
- Demonstrates process creation, sleep, and synchronization using fork(), sleep(), and wait().-

  ![Screenshot 2025-05-29 222305](https://github.com/user-attachments/assets/e7c4a91c-a446-4bf7-8c58-ce1e9ee5905b)

ex.c file outputs

Key Points:
- fork() creates child processes.
- sleep(n) pauses the process for n seconds.
- exit(n) ends the process with status n.
- wait(&status) waits for a child to finish.
- WEXITSTATUS(status) retrieves the exit code of the terminated child.

  ![Screenshot 2025-05-29 223816](https://github.com/user-attachments/assets/268502ab-031f-4b5b-a4f0-14f72d1584dd)


Explanation:
- First child sleeps for 2 seconds and exits with code 2.
- Second child sleeps for 1 second and exits with code 1.
- Parent uses wait() twice, and stores the order of completion.
- It prints which child finished first and second by PID and exit code.

  ![Screenshot 2025-05-29 223932](https://github.com/user-attachments/assets/5c74ba8e-5ffd-49b5-b03f-ad293fb5bec9)


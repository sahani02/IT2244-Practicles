🔹 Explanation:

- fork() creates a child process.
- Both parent and child execute the rest of the code.
- getpid() prints the PID of each process.
- fork() returns:
    * 0 to the child
    * PID of child to the parent

![Screenshot 2025-05-31 205910](https://github.com/user-attachments/assets/110a9cde-8daf-44b5-87be-8e3610afab16)


🔹 Explanation:

- If f == 0, it's the child process.
- Else, it’s the parent process.
- Prints who is parent or child along with their PID.

![Screenshot 2025-05-31 210610](https://github.com/user-attachments/assets/be42802d-9d56-4703-90b5-9bd786fe26f2)

🔹 Explanation:

- Two fork() calls create up to 4 processes:
- Each process executes both fork() calls independently.
- Output depends on order of execution.
- if-else conditions identify each process based on return value of fork().

![Screenshot 2025-05-31 211846](https://github.com/user-attachments/assets/a79128b0-d2a8-415d-adac-5fb1804e4acf)

🔹 Explanation:

- First fork() creates a child.
- The parent then creates another child (sibling of the first child) using a second fork().
- This results in 3 processes:
    * Parent
    * Child
    * Sibling (another child of the parent)
- getppid() shows each process’s parent PID.

![Screenshot 2025-05-31 212039](https://github.com/user-attachments/assets/244b37a7-a452-4523-9113-264490176733)

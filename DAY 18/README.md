**Exersice 1**
📌 Key Points for send :

ftok() generates a unique key based on file and id.

msgget() creates or accesses a message queue.

msgsnd() sends a message of type 1 to the queue.

Uses fgets() to input a short string (max 10 chars due to MAX 10).

📌 Key Points for recieve:

Uses the same ftok() and msgget() to access the same queue.

msgrcv() receives a message of type 1.

msgctl(..., IPC_RMID, ...) deletes the message queue after receiving the message to clean up resources.

![Screenshot 2025-05-31 214049](https://github.com/user-attachments/assets/11092950-a225-49bc-8517-1a0f17050f25)

**Exersice 2**
 The program: 

- Uses fork() to create a parent and a child process.
-The parent collects input (Name, RegNo, Age) from the user and sends it to a System V message queue.
-The child receives the message and displays the received information.

✅ Structure Definition

		struct person {
			long mtype;
			int age;
			char name[MAX_NAME_LEN];
			char regno[MAX_REGNO_LEN];
		};
		
- mtype: Required by message queue, indicates the message type.
- name, regno, age: Information about a person to be sent.

✅ Key Functions Used

- fork()	: Creates a child process.
- msgget()	: Creates or accesses a message queue using a unique key (MSGKEY = 1111).
- msgsnd()	: Sends a message (the person's data) from the parent to the queue.
- msgrcv()	: Child receives the message from the queue.
- msgctl()	: Deletes the message queue after receiving to free system resources.

✅ Process Flow
👨‍👦 Parent Process (Sender)
- Creates/accesses message queue.

- Collects:
	* Name
	* RegNo
	* Age

- Sends the struct to the message queue using msgsnd().
- Displays "Message sent successfully."

👶 Child Process (Receiver)

- Accesses the same message queue.
- Waits for a message using msgrcv().

- Prints:

	* Received Name
	* Received RegNo
	* Received Age

- Deletes the queue using msgctl().
- IPC_CREAT | 0666 creates the queue with read/write permissions if it doesn't exist.
- msgctl(..., IPC_RMID, ...) ensures that the message queue is deleted after use.
![Screenshot 2025-05-31 214237](https://github.com/user-attachments/assets/37aae8be-f964-4a63-a604-62cd7828959d)

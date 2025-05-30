//send
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 10
// structure for message queue
struct msg_buffer{
	long mesg_type;
	char mesg_text[100];
}message;
int main(){
	key_t key;
	int msgid;
	//ftok to generate unique key 
	key=ftok("progfile",65);
	//msgget creats a message queue//and returns identifier
	msgid=msgget(key, 0666 | IPC_CREAT);
	message.mesg_type=1;
	printf("write DATA: ");
	fgets(message.mesg_text,MAX,stdin);
	//msgsnd to send message
	msgsnd(msgid, &message, sizeof(message), 0);
	//display the message
	printf("Data send is : %s \n", message.mesg_text);
	return 0;
}

//receive
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
//structure fpor message queue
struct msg_buffer{
	long mesg_type;
	char mesg_text[100];
}message;
int main(){
	key_t key;
	int msgid;
	//ftok to generate unique key 
	key=ftok("progfile",65);
	//msgget creats a message queue//and returns identifier
	msgid=msgget(key, 0666 | IPC_CREAT);
	//msgrcv to receive message
	msgrcv(msgid, &message, sizeof(message), 1, 0);
	//display the message
	printf("Data Received is : %s \n",message.mesg_text);
	//to distroy the message queue
	msgctl(msgid, IPC_RMID,NULL);
	return 0;
}
	
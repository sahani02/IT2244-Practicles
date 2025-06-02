//write process1
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syd/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024//size of shared memmory segment

int main(){
	key_t key=ftok("shmfile",1510);//Generate unique key
	int shmid=shmget(key,SHM_SIZE,IPC_CREAT | 0666); //create shared memory segment
	if(shmid==-1){
		perror("shmget");
		exit(1);
	}
	
	char *shmaddr=(char*) shmat(shmid,NULL,0);//Attach to shared memeory
	if(shmaddr==(char*)-1){
		perror("shmat");
		exit(1);
	}
	printf("Write Data: ");
	fgets(shmaddr,SHM_SIZE,stdin);//write data to shared memmory
	printf("Data writen in memmory: %s\n",shmaddr);
	shmdt(shmaddr);//detach from shared memmory
	return 0;
}
	
//reader
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <syd/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE 1024//size of shared memmory segment
int main(){
	key_t key=ftok("shmfile",1510);//Generate unique key
	int shmid=shmget(key,SHM_SIZE, 0666); //create shared memory segment
	if(shmid==-1){
		perror("shmget");
		exit(1);
	}
	char *shmaddr=(char*) shmat(shmid,NULL,0);//Attach to shared memeory
	if(shmaddr==(char*)-1){
		perror("shmat");
		exit(1);
	}
		
	printf("Data read from memory: %s\n", shmaddr);//read data from shared memory
	shmdt(shmaddr);//Detach from shared memory
	shmctl(shmid,IPC_RMID,NULL);//Remove shared segment
	return 0;
}
		
/*Exercise

1.read two input from user(//parent process)
name:
reg no:
age:

2.print the output from the child(//child process)
name:abc
reg no:2022/ict/01
age:25
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MSGSIZE 16

int main(){
	int p[2],i;
	char* name[MSGSIZE],reg_no[MSGSIZE],age[MSGSIZE];
	
	
	if(pipe(p)<0){
		perror("Pipe Failed");
		exit(1);
	}
	int f=fork();
	if(f==0){
		close(p[1]);
		for(i=0;i<3;i++){
			char inbuf[MSGSIZE];
			read(p[0], inbuf, MSGSIZE);//read(filedes,msg,msgsize)
			printf("%s\n", inbuf);
		}
		close(p[0]);
		
	}
	
	else{
		close(p[0]);
		printf("Name: ");
		scanf("%s",&name);
		printf("reg_no: ");
		scanf("%s", &reg_no);
		printf("age: ");
		scanf("%s", &age);
		
		write(p[1],name,MSGSIZE); //write(fildes,message,message size)
		write(p[1],reg_no,MSGSIZE);
		write(p[1],age,MSGSIZE);
		
	}
	return 0;
}


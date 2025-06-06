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
char* name;
char* reg_no;
char* age;

int main(){
	char inbuf[MSGSIZE]; //[]
	int p[2], i;
	char arr[MSGSIZE];
	int f=fork();
	if(f==0){
		printf("Name: ");
		scanf("%s", &name);
		printf("reg_no: ");
		scanf("%s", &reg_no);
		printf("age: ");
		scanf("%d", &age);
		
	}
	else if(f==0){
		printf("child process output ");
		printf("Name: ",&name);
		printf("reg_no: ", &reg_no);
		printf("age: ", &age);
		
		write(p[1],name,MSGSIZE); //write(fildes,message,message size)
		write(p[1],reg_no,MSGSIZE);
		write(p[1],age,MSGSIZE);
	}
	else{
		wait(NULL);
	}
	return 0;
}


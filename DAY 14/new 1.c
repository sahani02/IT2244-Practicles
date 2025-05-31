//fork() and PId
#include<stdio.h>
#include<unistd.h>
int main(){
printf("\nHello world!");
int f=fork();
int p=getpid();
printf("\n the pid is %d", p);
printf("\n the fork is %d", f);
return 0;
}



#include<stdio.h>
#include<unistd.h>
int main(){
	
int f=fork();
if(f==0){
	printf("i am child %d\n",getpid() );
}
else{
	printf("I am perent %d\n",getpid());
}
return 0;
}



#include<stdio.h>
#include<unistd.h>
int main(){
	
int f1=fork();
int f2=fork();
if(f1==0){
	printf("I am child %d\n",getpid());
	
}
else if(f2==0){
	printf("I am sibling %d\n",getpid());
}
else{
	printf("I am parent %d\n",getpid());
}
return 0;
}

#include<stdio.h>
#include<unistd.h>
int main(){

	int f=fork();
	if(f==0){
			printf("i am child. my id  %d my parent id %d\n", getppid(),getpid());
	}
	else{
			int f1=fork();
			if(f1==0){
			  printf("i am sibiling. my parent id %d My id is %d  \n", getppid(),getpid());
			}
			else{
					printf("i am parent. my parent id is %d my id is  %d\n", getppid(),getpid());
			}
	}
return 0;
}

/*exircise:
First child:sept for 1 second.
Second child:sept for 3 second.
parent:Both children have finished.*/

#include <stdio.h>
#include <stdlib.h>//for exit()
#include <unistd.h>//for sleep()
#include <sys/wait.h> //for wait()
int main(){
	pid_t pid,pid1;
	printf("Program process started.PID: %d\n",getpid());
	
	pid=fork();//create a new child process
	if(pid<0){
		perror("fork faild");
		exit(1);
	}
	if(pid==0){
		//child process
		printf("Child process. PID: %d,sleeping for 1 seconds..\n",getpid());
		sleep(1);
		printf("Child process exiting.\n");
		exit(0);//wait for child exits  status 0
	}
	else{
		
		pid1=fork();//create a second child
        if(pid1==0){
        //child process
        printf("Child process. PID: %d,sleeping for 3 seconds..\n",getpid());
        sleep(3);
        printf("Child process exiting.\n");
        exit(0);//wait for child exits  status 0
        }
        else{
			wait(NULL);
			wait(NULL);
			printf("Both are finished.pid:%d\n", getpid());
        }

	}
		
	return 0;
}
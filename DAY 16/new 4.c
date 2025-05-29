#include <stdio.h>
#include <stdlib.h>//for exit()
#include <unistd.h>//for sleep()
int main(){
	printf("Program started.\n");
	
	printf("Sleeping for 3 seconds..\n");
	sleep(3);//pause for 3 seconds
	
	printf("Exiting the program..\n");
	exit(0);//clean exit
	
	return 0;
}

#include <stdio.h>
#include <stdlib.h>//for exit()
#include <unistd.h>//for sleep()
#include <sys/wait.h> //for wait()
int main(){
	pid_t pid;
	printf("Program process started.PID: %d\n",getpid());
	
	pid=fork();//create a new child process
	if(pid<0){
		perror("fork faild");
		exit(1);
	}
	if(pid==0){
		//child process
		printf("Child process. PID: %d,sleeping for 2 seconds..\n",getpid());
		sleep(2);
		printf("Child process exiting.\n");
		exit(0);//wait for child exits  status 0
	}
	else{
		//parent process
		int status;
		printf("Parent waiting for child to finish..\n");
		wait(&status);//wait for child to finish
		if(WIFEXITED(status)){//WIFEXITED(status) returns true if child terminated normally.
			
			printf("child exited with status: %d\n",WEXITSTATUS(status));
			//WEXITSTATUS(status) get the actual exit code(0 here).
		}
		else{
			printf("child did not exit normally.\n");
		}
		printf("Parent process ending.\n");
	}
	
	return 0;
}
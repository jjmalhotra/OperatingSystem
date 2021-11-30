#include <stdio.h>
#include<sys/types.h> //return value of fork() -pid
#include<stdlib.h>
#include<unistd.h>

int main()
{	
	pid_t cpid; //cpid is a var of data type pid_t i.e. int to store (+ve, -ve or 0)
	cpid = fork();  //create the process with id stored in cpid

	if ( cpid < 0){ //-ve value
		printf("\n Cannot create the process");
		exit(0);
	}

	if( cpid == 0 ) { //CHILD PROCESS
		sleep(50);  //Demonstrate orphan state
		printf("\n****** This is child process ********\n ");
		printf("\n\t Child process id is : %d", getpid());
		printf("\n\t Parent process id is : %d\n", getppid());
		printf("\n******Child process terminates *******\n");			
	}
	else { //Parent process 	
		sleep(30);  //to demonstrate zombie state
		printf("\n\n\t Parent process");
		printf("\n\t Parent process id is : %d\n", getpid());	
		printf("\n\t Parent process id is : %d\n", getppid());	
	}//end of if-else
	return 0;	
}//end of main

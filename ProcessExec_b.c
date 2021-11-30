//Execute ls command from the child process

#include <unistd.h>  //for execv
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	pid_t pid;
	int arr[10];
	char * argv_list[] = {"ls","-lrt","/home/hp/Botnet", NULL}; // ls -lart /home/  NULL - no more arg

	pid=fork();    

	if(pid==0)  //child process
	{
		execv("/bin/ls",argv_list); //arg1 - path of the executable		
		printf("\n This is child \n");
	}
	else //parent process
	{
		//sleep(30);  
		printf("\n This is parent process\n");
	}
}

//Execute other executable (pa program) from the child process

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 20
#include "defined_function.h"
int main()
{
	pid_t pid;
	int arr[10];
	char * argv_list[] = {"pa"}; // Execute pa
	pid=fork();    

	if(pid==0)  //child process
	{
		execv("./pa",argv_list);	
	}
	else //parent process
	{
		sleep(40);  
		printf("\n This is parent process\n");
	}
}

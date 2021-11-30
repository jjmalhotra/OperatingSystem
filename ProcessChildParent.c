/*
@author: Jyoti Malhotra
Implement following programs to exhibit UNIX Process Control 
Parent process 	- sorts array elements in ascending order 
				- Count number of vowels in the given sentence

Child process 	- sorts array elements in descending order 
				- Count number of words in the given sentence
Demonstrate wait system call; where parent process waits for child process to terminate
*/

#include <stdio.h>
#include<sys/types.h>  //fork, getpid, getppid
#include<sys/wait.h>    //wait to avoid Orphan and Zombie conditions
#include<stdlib.h>	//exit
#include<unistd.h>
#define MAX 20
#include "defined_function.h" //user defined file



/*
The  <sys/types.h>  header file include  definitions for system data types such as : 
pid_t ( Used for process IDs ). 
All the data types defined under sys types are appended by _t
*/

int main()
{
	char str[20];	//For sentence operations
	int arr[MAX], *status=NULL;  //For array sorting and collecting the exit status of child process
	pid_t cid;		//Var for child process ID with the data type pid_t
	
	fflush(stdout);	

	accept_str(str);	//Accept the sample sentence
	accept_nos(arr);	//Accept the numbes for an array

	cid = fork();		//Main process forks/clones the new process - child

	if( cid == 0 ) //CHILD PROCESS
	{
		printf("\n*************** This is child process ***************\n ");
		printf("\n\t My process id is : %d", getpid());
		printf("\n\t My Parent process id is : %d", getppid());
		sleep(5);  //for output readability
		sort_desc(arr);
		sleep(5);  //for output readability
		cnt_words(str);	
		printf("\n*************Child process terminates ***************\n");	
		sleep(5);  //for output readability		
	}
	else
	{
	/*Parent process waiting for child process, sorting array elements in descending 	order and calculating number of words in given statement.*/
		cid = wait(status);	//to avoid zombie and orphan state
		printf("\n\n\t Parent process resumed after the execution of child process with PID %d", cid);

		printf("\n\t My process id is : %d", getpid());
		printf("\n\t My Parent process id is : %d", getppid());
		sleep(5);  //for output readability
		printf("\n Parent process sorting the number in ascending order:\n");
		sort_asc(arr);
		sleep(5);  //for output readability
		cnt_vowels(str);	
		sleep(5);  //for output readability
		
	}//end of if-else

	return 0;	
}//end of main

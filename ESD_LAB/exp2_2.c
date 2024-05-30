/*Write a C program to demonstrate the use of signal function calls: Handle ctrl+C, ignore ctrl+Z, find a method to
terminate the process*/


#include<signal.h>
#include<stdio.h>
#include<unistd.h>

void handler1(int signal)
{
	printf("\nCtrl+C Encountered");
}

void main()
{
	(void) signal(SIGINT, handler1);
	(void) signal(SIGTSTP,SIG_IGN);
	while(1)
	{
		printf("%d\n",getpid());
		sleep(1);
	}
}


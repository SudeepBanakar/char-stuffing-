/*Write a C program to demonstrate the use of signal function calls: When ctrl+C is used, a signal is sent for abrupt
termination.*/

#include<signal.h>
#include<stdio.h>
#include<unistd.h>

void handler(int signal)
{
	printf("\nProblem Encountered:%d\n",signal);
}

void main()
{
	(void) signal(SIGINT, handler);
	while(1)
	{
		printf("Hello\n");
		sleep(2);
	}
}


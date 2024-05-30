/*Write a C program to demonstrate the use of signal function calls: Ignore the signal when ctrl+C is pressed.*/

#include<signal.h>
#include<stdio.h>
#include<unistd.h>

void main()
{
	(void) signal(SIGINT, SIG_IGN);
	while(1)
	{
		printf("%d\n",getpid());
		sleep(1);
	}
}


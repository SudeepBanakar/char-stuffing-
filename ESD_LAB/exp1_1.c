#include<stdio.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdlib.h>

int main()
{
pid_t pid;
char *message;
int no,no1,i,j;
printf("calling fork\n");
pid=fork();
switch(pid)
{
case -1: printf("fork failed\n`````");
         exit(1);
case 0: message = "child process";
        i=1;
        no=getpid();
        no1=getppid();
        break;
default: message = "parent process";
        i=1;
        no=getpid();
        no1=getppid();
        break;       
}

if(pid!=0)
{
printf("Hello from parent\n");
wait(NULL);
printf("Child process terminated\n");
}

for(j=i;j>0;j--)
{
puts(message);
printf("my id is %d\n",no);
printf("my parent id is %d\n",no1);
}
return 0;
}

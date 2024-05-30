#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<pthread.h>
#include<semaphore.h>

#define bs 1024
sem_t sem;
char buffer[bs];

void *read_thread(void *arg)
{
while(strncmp("stop",buffer,4)!=0)
{
printf("Enter text:\n");
fgets(buffer,bs,stdin);
sem_post(&sem);
sleep(1);
}
pthread_exit("Read thread exit success");
}

void *convert_thread(void *arg)
{
int i;
sem_wait(&sem);
while(strncmp("stop",buffer,4)!=0)
{
printf("Converted text:\n");
for(i=0;i<strlen(buffer);i++)
printf("%c",toupper(buffer[i]));
sem_wait(&sem);
}
pthread_exit("Convert thread exit success");
}

int main()
{
sem_init(&sem,0,1);
pthread_t rth,cth;
void *res;
printf("Enter text to be converted to upper case \n to stop enter stop\n");
pthread_create(&rth,NULL,read_thread,NULL);
pthread_create(&cth,NULL,convert_thread,NULL);
pthread_join(rth,&res);
printf("Read thread joined, %s\n",(char*)res);
pthread_join(cth,&res);
printf("Convert thread joined, %s\n",(char*)res);
sem_destroy(&sem);
return 0;
}


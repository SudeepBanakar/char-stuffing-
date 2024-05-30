#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<pthread.h>

#define bs 1024
char buffer[bs];

void *read_thread(void *arg)
{
while(strncmp("stop",buffer,4)!=0)
{
printf("Enter text:\n");
fgets(buffer,bs,stdin);
sleep(1);
}
pthread_exit("Read thread exit success");
}

void *convert_thread(void *arg)
{
while(strncmp("stop",buffer,4)!=0)
{
int i;
sleep(1);
printf("Converted text:\n");
for(i=0;i<strlen(buffer);i++)
printf("%c",toupper(buffer[i]));
}
pthread_exit("Convert thread exit success");
}

int main()
{
pthread_t rth,cth;
void *res;
printf("Enter text to be converted to upper case \n to stop enter stop\n");
pthread_create(&rth,NULL,read_thread,NULL);
pthread_create(&cth,NULL,convert_thread,NULL);
pthread_join(rth,&res);
printf("Read thread joined, %s\n",(char*)res);
pthread_join(cth,&res);
printf("Convert thread joined, %s\n",(char*)res);
return 0;
}


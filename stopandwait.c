#include<stdio.h>
#include<string.h>
#include<unistd.h>
# define w 1
int main(){
    int n,frames[30],f;
    printf("enter the number of frames");
    scanf("%d",&n);
    for(int f=0;f<n;f++)
        scanf("%d",&frames[f]);
    printf("stop and wait\n");
    printf("after sending %d\n",w);
    printf("if error occur resend\n");
    for(int i=1;i<n;i++){
        if(random()%2==1){
            if(i%w==0){
                printf("%d\n",frames[i]);
            }
            else{
                printf("%d\n",frames[i]);
            }
            
        }
        else{
            sleep(3);
            printf("%d -ve ack resend it\n",i);
            i=i-1;
            sleep(1);
        }
    }
}

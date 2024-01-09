#include  <stdio.h>
#include <string.h>
#define N strlen(gen)
char data[128];
char gen[128];
char check_value[128];
int data_length,j,i;
void receiver(){
// get the received data
    printf("Enter the received data: ");
    scanf("%s", data);
    printf("Data received: %s", data);
// Cyclic Redundancy Check
    crc();
// Check if the remainder is zero to find the error
    for(i=0;(i<N-1) && (check_value[i]!='1');i++);
        if(i<N-1)
            printf("\n noError detected\n\n");
        else
            printf("\n error detected\n\n");
}
void crc(){
    for(int i=0;i<N;i++)
        check_value[i]=data[i];
    do{
        if(check_value[0]=='1')
        xor();
    for(int j=0;j<N;j++)
        check_value[j]=data[j+1];
        
        check_value[j]=data[i++];
        }while(i<data_length+N-1);
    
}
void xor(){
     for(int j = 1;j < N; j++)
    check_value[j] = (( check_value[j] == gen[j])?'0':'1');
    
}
void main()
{
    printf("enter the data poly");
    scanf("%s",data);
    int data_length=strlen(data);
    printf("enter the gen poly");
    scanf("%s",gen);
    for(int i=data_length;i<data_length+N-1;i++)
        data[i]='0';
    printf("apended data %s",data);
    crc();
    printf("\nCRC or Check value is : %s",check_value);
    for(i=data_length;i<data_length+N-1;i++)
        data[i]=check_value[i-data_length];
    printf("\n Final data to be sent : %s",data);
    receiver();    
}

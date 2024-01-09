#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
 char c[50],d[50],t[50];int i,j,n;
 printf("Enter the no of characters:\n");
 scanf("%d",&n);
 printf("Enter the String:\n");
 for(i=0;i<n+1;i++)
  scanf("%c",&c[i]);
 printf("\nThe Original String:\n");
 for(i=0;i<n+1;i++)
  printf("%c",c[i]);
 d[0]='d'; 
 d[1]='l'; 
 d[2]='e'; 
 d[3]='s'; 
 d[4]='t'; 
 d[5]='x'; 
 for(i=0,j=6;i<n+1;i++,j++)
 {
  if(c[i]=='d' && c[i+1]== 'l' && c[i+2]=='e')
  {
    d[j]='d';j++;
    d[j]='l';j++;
    d[j]='e';j++;
    n=n+3;
  }
  d[j]=c[i];
 }
 n=n+6;
 n++;
 d[n]='d';n++;
 d[n]='l';n++;
 d[n]='e';n++;
 d[n]='s';n++;
 d[n]='t';n++;
 d[n]='x';n++;
 printf("\nThe Transmitted Data:\n");
 for(i=0;i<n;i++)
  printf("%c",d[i]);
  for(i=6,j=0;i<n-6;i++,j++)
  {
   if(d[i]=='d' && d[i]=='l' && d[i]=='e' && d[i]=='d' && d[i]=='l' && d[i]=='e')
    i=i+3;
    t[j]=d[i];
  }
  printf("\nThe Recieved Data:\n");
  for(i=0;i<j;i++)
   printf("%c",t[i]);
}

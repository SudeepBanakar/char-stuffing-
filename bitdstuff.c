#include<stdio.h>
#include<string.h>

int main()
{
    int a[20],b[20],i,j,k,n,count;
    printf("enter frame size");
    scanf("%d",&n);
    printf("enter the bits");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    i=0;
    j=0;
    count=1;
    while(i<n){
        if(a[i]==1){
            b[j]=a[i];
            for(k=i+1;a[k]==1 && k<n && count<5;k++){
                j++;
                b[j]=a[k];
                count++;
                if(count==5)
                {
                    k++;
                }
                i=k;
            }
            
        }
        else{
            b[j]=a[i];
            }
            i++;
            j++;
    }
    printf("after bit stuffing");
    for(i=0;i<j;i++)
    printf("%d",b[i]);
    

}

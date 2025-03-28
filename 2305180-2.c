#include<stdio.h>
#include<stdlib.h>

void freq(int *a, int *b, int n);

int main()
{
    int n;
    scanf("%d",&n);
    int *a,*b;
    a=(int *)malloc(n*sizeof(int));
    b=(int *)calloc(10001,sizeof(int));
    for(int i=0;i<n;i++)
    {
        scanf("%d",a+i);
    }
    freq(a,b,n);
    int max=0;
    
    for(int i=0;i<10000;i++)
    {
        if(*(b+i)>=max){
            max=*(b+i);
    
        }
    }
    for(int i=0;i<10000;i++)
    {
        if(*(b+i)==max){
            printf("%d ",i);
        }
    }
    
    free(a);
    free(b);
}


void freq(int *a, int *b, int n)
{
    
    for(int i=0;i<n;i++)
    {
        if(*(a+i)==-1)continue;
        int x=*(a+i);
        int f=0;
        for(int j=i;j<n;j++)
        {
            if(*(a+j)==x)
            {
                f++;
                *(a+j)=-1;
            }
        }
        *(b+x)=f;
    }
    return;
}
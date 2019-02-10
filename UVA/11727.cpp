#include<stdio.h>
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int a[3];
        scanf("%d%d%d",&a[0],&a[1],&a[2]);
        if(a[0]>a[1])swap(&a[0],&a[1]);
        if(a[1]>a[2])swap(&a[1],&a[2]);
        if(a[0]>a[1])swap(&a[0],&a[1]);
        printf("Case %d: %d\n",i,a[1]);
    }
    return 0;
}

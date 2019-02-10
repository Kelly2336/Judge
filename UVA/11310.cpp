//DP
#include<stdio.h>
unsigned long long int a[41];
void cake()
{
    a[1]=1;
    a[2]=5;
    a[3]=11;
    for(int i=4;i<=40;i++)
    {
        a[i]=a[i-3]*2+a[i-2]*4+a[i-1];
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    cake();
    for(;t>0;t--)
    {
        int n;
        scanf("%d",&n);
        printf("%llu\n",a[n]);
    }
    return 0;
}

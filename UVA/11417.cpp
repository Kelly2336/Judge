#include<stdio.h>
#include<string.h>
int gcd(int a,int b)
{
    if(a%b==0)return b;
    return gcd(b,a%b);
}
int main()
{
    long long int a[505];
    memset(a,0,sizeof(a));
    a[1]=0;
    for(int i=2;i<=500;i++)
    {
        a[i]=a[i-1];
        for(int j=1;j<i;j++)
        {
            a[i]+=gcd(j,i);
        }
    }
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        printf("%lld\n",a[n]);
    }
    return 0;
}

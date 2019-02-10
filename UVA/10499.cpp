#include<stdio.h>
int main()
{
    long long int n;
    while(scanf("%lld",&n)>=1&&n>=0)
    {
        if(n<=1)printf("0%%\n");
        else printf("%lld%%\n",n*25);
    }
    return 0;
}
//原=4*pi*r^2;
//後=4*pi*r^2+n*pi*r^2;

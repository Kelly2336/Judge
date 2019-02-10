#include<stdio.h>
#include<iostream>
using namespace std;
unsigned long long int dp[1000005];
int main()
{
    dp[3]=0;
    dp[4]=1;
    for(int i=5;i<=1000000;i++)
    {
        long long int i2=i/2;
        dp[i]=(i-1-i2)*(i2-1)+dp[i-1];
        /*for(int j=i-1;j>i/2;j--)
        {
            dp[i]+=j-(i-j+1);
        }*/
    }
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n<3)break;
        printf("%llu\n",dp[n]);
    }
    return 0;
}

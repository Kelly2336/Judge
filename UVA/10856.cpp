#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;
#define MAX 2750000
int dp[MAX]={0,0,1};
int f[MAX]={0,0,1};
int prime[200000]={2};
int main()
{
    int pi=1;
    for(int i=3;i<MAX;i++)
    {
        int sq=sqrt(i);
        f[i]=1;
        for(int j=0;j<pi&&prime[j]<=sq;j++)
        {
            if(i%prime[j]==0)
            {
                f[i]+=f[i/prime[j]];
                break;
            }
        }
        if(f[i]==1)
        {
            prime[pi]=i;
            pi++;
        }
        dp[i]=dp[i-1]+f[i];
    }
    int n,cas=1;
    while(1)
    {
        scanf("%d",&n);
        if(n<0)break;
        int t=lower_bound(dp,dp+min(n+1,MAX),n)-dp;
        printf("Case %d: ",cas);
        cas++;
        if(dp[t]==n)printf("%d!\n",t);
        else printf("Not possible.\n");
    }
    return 0;
}

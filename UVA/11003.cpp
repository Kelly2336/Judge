//DP
//LIS
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int n;
    int w[1005];
    int v[1005];
    int dp[1005];
    while(1)
    {
        scanf("%d",&n);
        if(!n)break;
        for(int i=0;i<n;i++)scanf("%d%d",&w[i],&v[i]);
        int ans=1;
        dp[0]=0;
        dp[1]=w[n-1];
        for(int i=n-2;i>=0;i--)
        {
            int j=ans-1;
            if(dp[ans]<=v[i])
            {
                dp[ans+1]=dp[ans]+w[i];
                ans++;
            }
            for(;j>=0;j--)
            {
                if(dp[j]<=v[i])
                {
                    dp[j+1]=min(dp[j+1],dp[j]+w[i]);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

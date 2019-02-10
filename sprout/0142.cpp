//取數字2
//DP
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        int a[1005];
        int dp[1005];
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            dp[i]=a[i];
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+k;j<i+2*k&&j<=n;j++)
            {
                dp[j]=max(dp[j],dp[i]+a[j]);
            }
            if(dp[i]>ans)ans=dp[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}

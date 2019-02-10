//合成円円
//DP
//類似矩陣乘法
#include<stdio.h>
#include<iostream>
using namespace std;
long long int INF=1e18;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[105];
        int sum[105]={0};
        for(int i=1; i<=n; i++)
        {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        long long int dp[105][105];
        for(int i=1; i<=n; i++)dp[i][i]=0;
        for(int k=1; k<=n-1; k++)
        {
            for(int l=1,r=1+k; r<=n; l++,r++)
            {
                dp[l][r]=INF;
                for(int i=l; i<r; i++)
                {
                    dp[l][r]=min(dp[l][r],dp[l][i]+dp[i+1][r]+sum[r]-sum[l-1]);
                }
            }
        }
        printf("%lld\n",dp[1][n]);
    }
    return 0;
}

//取數字1
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
        int n;
        scanf("%d",&n);
        int a[100005];
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        int dp[100005][2];
        dp[1][0]=0;
        dp[1][1]=a[1];
        for(int i=2;i<=n;i++)
        {
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]);
            dp[i][1]=dp[i-1][0]+a[i];
        }
        printf("%d\n",max(dp[n][0],dp[n][1]));
    }
    return 0;
}

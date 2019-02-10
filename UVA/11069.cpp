#include<stdio.h>
using namespace std;
int main()
{
    int dp[2][80];
    dp[0][1]=1;
    dp[1][1]=0;
    dp[0][2]=0;
    dp[1][2]=1;
    dp[0][3]=1;
    dp[1][3]=0;
    int ans[80]={0,1,2,2};
    for(int i=4;i<=76;i++)
    {
        dp[0][i]=dp[0][i-2]+dp[0][i-3];
        dp[1][i]=dp[1][i-2]+dp[1][i-3];
        ans[i]=dp[0][i-1]+dp[1][i-1]+dp[0][i]+dp[1][i];
    }
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("%d\n",ans[n]);
    }
    return 0;
}

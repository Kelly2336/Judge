//円円送禮物
//DP
#include<stdio.h>
using namespace std;
int mod=1000007;
int main()
{
    long long int dp[100005][3][3];
    dp[1][0][0]=1;//red
    dp[1][0][1]=0;//green
    dp[1][0][2]=0;//blue
    dp[1][1][0]=0;//red
    dp[1][1][1]=1;//green
    dp[1][1][2]=0;//blue
    dp[1][2][0]=0;//red
    dp[1][2][1]=0;//green
    dp[1][2][2]=1;//blue
    for(int i=2;i<=100001;i++)
    {
        for(int j=0;j<=2;j++)
        {
            dp[i][j][0]=(dp[i-1][j][0]+dp[i-1][j][1]+dp[i-1][j][2])%mod;
            dp[i][j][1]=(dp[i-1][j][0]+dp[i-1][j][1])%mod;
            dp[i][j][2]=(dp[i-1][j][0]+dp[i-1][j][2])%mod;
        }
    }
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%lld\n",(dp[n][0][0]+dp[n][1][0]+dp[n][2][0]+dp[n][0][1]+dp[n][1][1]+dp[n][0][2]+dp[n][2][2])%mod);
    }
    return 0;
}

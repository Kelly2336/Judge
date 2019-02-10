//0:最底層沒鎖
//1:最底層有鎖
#include<stdio.h>
using namespace std;
int main()
{
    long long int dp[66][66][2];
    dp[0][0][0]=1;
    dp[0][0][1]=0;
    dp[1][0][0]=1;
    dp[1][0][1]=0;
    dp[1][1][0]=0;
    dp[1][1][1]=1;
    for(int i=2;i<=65;i++)
    {
        dp[i][0][0]=dp[i-1][0][1]+dp[i-1][0][0];
        dp[i][0][1]=dp[i-1][0][0];
        for(int j=1;j<i;j++)
        {
            dp[i][j][0]=dp[i-1][j][1]+dp[i-1][j][0];
            dp[i][j][1]=dp[i-1][j][0]+dp[i-1][j-1][1];
        }
        dp[i][i][1]=1;
        dp[i][i][0]=0;
    }
    int n,s;
    while(1)
    {
        scanf("%d%d",&n,&s);
        if(n<0&&s<0)break;
        if(s>n)printf("0\n");
        else printf("%lld\n",dp[n][s][1]+dp[n][s][0]);
    }
    return 0;
}

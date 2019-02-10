#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int n,m;
    int cas=0;
    while(scanf("%d%d",&n,&m)==2)
    {
        if(!n||!m)break;
        cas++;
        int dp[105][105];
        memset(dp,0,sizeof(dp));
        int a[105],b[105];
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        for(int i=1;i<=m;i++)scanf("%d",&b[i]);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(a[i]==b[j])dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        printf("Twin Towers #%d\n",cas);
        printf("Number of Tiles : %d\n\n",dp[n][m]);
    }
    return 0;
}

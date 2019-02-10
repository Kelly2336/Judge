//DP
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int L,N;
    int c[55];
    while(1)
    {
        scanf("%d",&L);
        if(!L)break;
        scanf("%d",&N);
        int dp[55][55]={0};
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&c[i]);
        }
        c[0]=0;
        c[N+1]=L;
        for(int len=2;len<=N+1;len++)
        {
            for(int i=0;i<=N+1-len;i++)
            {
                int j=i+len;
                dp[i][j]=1e9;
                for(int k=i+1;k<j;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+c[j]-c[i]);
                }
            }
        }
        printf("The minimum cutting is %d.\n",dp[0][N+1]);
    }
    return 0;
}

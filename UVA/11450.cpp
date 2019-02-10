//分組背包
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int T,M,C;
    int k[25];
    int v[25][25];
    scanf("%d",&T);
    while(T--)
    {
        int MIN_sum=0;
        scanf("%d%d",&M,&C);
        for(int i=1;i<=C;i++)
        {
            scanf("%d",&k[i]);
            int MIN=100000;
            for(int j=1;j<=k[i];j++)
            {
                scanf("%d",&v[i][j]);
                MIN=min(MIN,v[i][j]);
            }
            MIN_sum+=MIN;
        }
        if(MIN_sum>M)
        {
            printf("no solution\n");
            continue;
        }
        bool dp[205];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        int MAX=0;
        for(int i=1;i<=C;i++)
        {
            for(int j=M;j>=0;j--)
            {
                for(int r=1;r<=k[i];r++)
                {
                    if(v[i][r]<=j&&dp[j-v[i][r]])
                    {
                        dp[j]=true;
                        MAX=max(MAX,j);
                    }
                }
            }
        }
        printf("%d\n",MAX);
    }
    return 0;
}

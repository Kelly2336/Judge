#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
    int T,N,p,w,G,x;
    int dp[35];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        memset(dp,0,sizeof(dp));
        while(N--)
        {
            scanf("%d%d",&p,&w);
            for(int i=30;i>=w;i--)
            {
                dp[i]=max(dp[i],dp[i-w]+p);
            }
        }
        scanf("%d",&G);
        int sum=0;
        while(G--)
        {
            scanf("%d",&x);
            sum+=dp[x];
        }
        printf("%d\n",sum);
    }
    return 0;
}

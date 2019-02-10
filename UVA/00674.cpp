#include<stdio.h>
using namespace std;
int main()
{
    int dp[7849]={0};
    int coin[5]={1,5,10,25,50};
    dp[0]=1;
    for(int i=0;i<5;i++)
        for(int j=coin[i];j<=7849;j++)
            dp[j]+=dp[j-coin[i]];
    int n;
    while(scanf("%d",&n)==1)
        printf("%d\n",dp[n]);
    return 0;
}

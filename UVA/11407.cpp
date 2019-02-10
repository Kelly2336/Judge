//DP
#include<stdio.h>
#include<string.h>
#include<cmath>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    int a[102];
    for(int i=0; i<102; i++)a[i]=i*i;
    int dp[10010];
    memset(dp,0,sizeof(dp));
    for(int i=1; i<=100; i++)
    {
        for(int j=a[i]; j<=10000; j++)
        {
            if(!dp[j]||dp[j-a[i]]+1<dp[j])
            {
                dp[j]=dp[j-a[i]]+1;
            }
        }
    }
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",dp[n]);
    }
    return 0;
}

#include<stdio.h>
#include<string.h>
using namespace std;
#define MAX 10005
int main()
{
    long long int dp[MAX]={0};
    memset(dp,0,sizeof(dp));
    int c[11]={1,2,4,10,20,40,100,200,400,1000,2000};
    dp[0]=1;
    for(int i=0;i<11;i++)
    {
        for(int j=c[i];j<MAX;j++)
        {
            dp[j]+=dp[j-c[i]];
        }
    }
    while(1)
    {
        double q;
        scanf("%lf",&q);
        if(q<0.01)break;
        int r=int(q*20+0.1);
        printf("%6.2f%17lld\n",q,dp[r]);
    }
    return 0;
}

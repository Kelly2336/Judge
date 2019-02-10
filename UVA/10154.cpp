//11003
//LIS
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int,int> ii;
int main()
{
    ii w[5610];
    int n=0;
    while(scanf("%d%d",&w[n].second,&w[n].first)==2)
    {
        //w[n].first-=w[n].second;
        n++;
    }
    sort(w,w+n);
    int ans=1;
    int dp[5610];
    dp[0]=0;
    dp[1]=w[0].second;
    for(int i=1;i<n;i++)
    {
        int j=ans-1;
        if(dp[ans]+w[i].second<=w[i].first)
        {
            dp[ans+1]=dp[ans]+w[i].second;
            ans++;
        }
        for(;j>=0;j--)
        {
            if(dp[j]+w[i].second<=w[i].first)
            {
                dp[j+1]=min(dp[j+1],dp[j]+w[i].second);
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}

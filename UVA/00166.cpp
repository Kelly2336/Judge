#include<stdio.h>
#include<iostream>
using namespace std;
#define INF 100000
int main()
{
    int c[6]={1,2,4,10,20,40};
    int change[45];
    fill(change,change+45,INF);
    change[0]=0;
    for(int i=0;i<6;i++)
    {
        for(int j=c[i];j<45;j++)
        {
            change[j]=min(change[j],change[j-c[i]]+1);
        }
    }
    int t[6];
    while(1)
    {
        int sum=0;
        for(int i=0;i<6;i++)
        {
            scanf("%d",&t[i]);
            sum+=t[i]*c[i];
        }
        if(!sum)break;
        double q;
        scanf("%lf",&q);
        int r=int(q*20+0.01);
        int dp[20005];
        fill(dp,dp+sum+10,INF);
        dp[0]=0;
        int ans=INF;
        if(sum>20000)sum=20000;
        for(int i=0;i<6;i++)
        {
            for(int j=1;t[i]>0;j*=2)
            {
                if(j>t[i])j=t[i];
                t[i]-=j;
                for(int k=sum;k>=j*c[i];k--)
                {
                    dp[k]=min(dp[k],dp[k-j*c[i]]+j);
                    if(k>=r&&k-r<45)ans=min(ans,dp[k]+change[k-r]);
                }
            }
        }
        printf("%3d\n",ans);
    }
    return 0;
}

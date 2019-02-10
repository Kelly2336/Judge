//裴裴與大薯
//LIS
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<vector>
using namespace std;
const int mod=1e9+7;
int main()
{
    int n;
    scanf("%d",&n);
    int a[5005];
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    int len[5005];
    int pre[5005];
    int dp[5005];
    int maxlen=0,maxi=0;
    for(int i=n;i>0;i--)
    {
        dp[i]=1;
        len[i]=1;
        pre[i]=0;
        for(int j=n;j>i;j--)
        {
            if(a[i]<=a[j])
            {
                if(len[j]+1>len[i])
                {
                    len[i]=len[j]+1;
                    pre[i]=j;
                    dp[i]=dp[j];
                }
                else if(len[j]+1==len[i])
                {
                    pre[i]=j;
                    dp[i]+=dp[j];
                }
                dp[i]%=mod;
            }
        }
        if(len[i]>=maxlen)
        {
            maxlen=len[i];
            maxi=i;
        }
    }
    int sum=0;
    for(int i=n-maxlen+1;i>=1;i--)
    {
        if(len[i]==maxlen)
        {
            sum+=dp[i];
            sum%=mod;
        }
    }
    printf("%d\n",maxlen);
    printf("%d\n",sum);
    printf("%d",maxi);
    int p=pre[maxi];
    while(p)
    {
        printf(" %d",p);
        p=pre[p];
    }
    printf("\n");
    return 0;
}

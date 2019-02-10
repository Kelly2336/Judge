//裴裴與大薯 - Extra
//LIS+二分搜
#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
const int mod=1e9+7;
#define maxn 100005
vector<int> v[maxn];
int main()
{
    int n;
    int a[maxn];
    int dp[maxn];
    int len[maxn];
    int pre[maxn];
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    len[n]=1;
    pre[n]=0;
    dp[n]=1;
    v[1].clear();
    v[1].push_back(n);
    int maxlen=1,maxi=n;
    int maxa=a[n];
    for(int i=n-1;i>=1;i--)
    {
        len[i]=1;
        pre[i]=0;
        dp[i]=1;
        v[n-i+1].clear();
        if(a[i]<=maxa)
        {
            int big=maxlen,small=1;
            while(big>=small)
            {
                int mid=(small+big)/2;
                bool success=false;
                int sum=0;
                int sz=v[mid].size();
                for(int vi=0;vi<sz;vi++)
                {
                    int t=v[mid][vi];
                    if(a[i]<=a[t])
                    {
                        success=true;
                        sum+=dp[t];
                        sum%=mod;
                        pre[i]=t;
                    }
                }
                if(success)
                {
                    len[i]=mid+1;
                    dp[i]=sum;
                    small=mid+1;
                }
                else big=mid-1;
            }
        }
        v[len[i]].push_back(i);
        if(len[i]>maxlen) maxlen=len[i];
        if(len[i]==maxlen) maxi=i;
        if(a[i]>maxa)maxa=a[i];
    }
    int ans=0;
    int sz=v[maxlen].size();
    for(int i=0;i<sz;i++)
    {
        ans+=dp[v[maxlen][i]];
        ans%=mod;
    }
    printf("%d\n",maxlen);
    printf("%d\n",ans);
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

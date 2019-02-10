#include<stdio.h>
#include<cmath>
using namespace std;
int f[1000005];
int ans[1000005];
int prime[80000];
int main()
{
    ans[2]=1;
    f[2]=1;
    int sq,i,j,pi=1;
    prime[0]=2;
    for(i=3;i<=1000000;i++)
    {
        f[i]=1;
        sq=sqrt(i);
        for(j=0;j<pi&&prime[j]<=sq;j++)
        {
            if(i%prime[j]==0)
            {
                f[i]=f[prime[j]]+f[i/prime[j]];
                break;
            }
        }
        ans[i]=ans[i-1]+f[i];
        if(f[i]==1)
        {
            prime[pi]=i;
            pi++;
        }
    }
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("%d\n",ans[n]);
    }
    return 0;
}

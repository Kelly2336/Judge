#include<stdio.h>
using namespace std;
int main()
{
    int ans[10005];
    ans[0]=1;
    for(int i=1;i<=10000;i++)
    {
        ans[i]=ans[i-1]*i;
        while(ans[i]%10==0)ans[i]/=10;
        ans[i]%=100000;
    }
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("%5d -> %d\n",n,ans[n]%10);
    }
    return 0;
}

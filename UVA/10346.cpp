#include<stdio.h>
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)>=1)
    {
        int ans=0;
        while(n>=k)
        {
            ans+=n/k*k;
            n=n%k+n/k;
        }
        ans+=n;
        printf("%d\n",ans);
    }
    return 0;
}

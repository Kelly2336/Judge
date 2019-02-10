#include<stdio.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        long long ans=0;
        for(int i=1;i<=n;)
        {
            int t=n/i;
            if(!t)break;
            int ii=n/t;
            ans+=t*(ii-i+1);
            i=ii+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

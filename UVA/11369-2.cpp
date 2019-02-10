#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int p[20005];
        for(int i=0;i<n;i++)
            scanf("%d",&p[i]);
        sort(p,p+n);
        int ans=0;
        for(int i=n-3;i>=0;i-=3)
        {
            ans+=p[i];
        }
        printf("%d\n",ans);
    }
    return 0;
}

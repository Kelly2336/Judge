//東方古墓古文
//二分搜+G
#include<stdio.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int s[100050];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&s[i]);
        }
        int ans=1200000000;
        int small=1;
        int big=1100000000;
        while(small<=big)
        {
            int mid=(small+big)/2;
            int p=1;
            int now=0;
            for(int i=0;i<n&&p<=m;i++)
            {
                now+=s[i];
                if(now>mid)
                {
                    p++;
                    now=s[i];
                    if(now>mid)p=m+1;
                }
            }
            if(p>m)
            {
                small=mid+1;
            }
            else
            {
                big=mid-1;
                if(mid<ans)ans=mid;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

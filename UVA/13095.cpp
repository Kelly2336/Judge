#include<stdio.h>
using namespace std;
#define maxn 100005
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        short int cnt[maxn][10]={0};
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            for(int j=0;j<10;j++)cnt[i][j]=cnt[i-1][j];
            cnt[i][x]++;
        }
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            int ans=0;
            for(int i=0;i<10;i++)
            {
                if(cnt[r][i]-cnt[l-1][i])ans++;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}

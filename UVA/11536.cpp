//sliding window
//爬行法
#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
    int T;
    scanf("%d",&T);
    for(int ti=1;ti<=T;ti++)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        int cnt[105]={0};
        a[1]=1,a[2]=2,a[3]=3;
        int ans=10000000;
        int zero=k;
        int len=0;
        for(int i=1;i<=n;i++)
        {
            if(i>3)a[i]=(a[i-1]+a[i-2]+a[i-3])%m+1;
            len++;
            if(a[i]<=k)
            {
                cnt[a[i]]++;
                if(cnt[a[i]]==1)
                {
                    zero--;
                    while(!zero)
                    {
                        ans=min(ans,len);
                        len--;
                        int t=i-len;
                        if(a[t]<=k)
                        {
                            cnt[a[t]]--;
                            if(!cnt[a[t]])zero++;
                        }
                    }
                }
            }
        }
        printf("Case %d: ",ti);
        if(ans>n)printf("sequence nai\n");
        else printf("%d\n",ans);
    }
    return 0;
}

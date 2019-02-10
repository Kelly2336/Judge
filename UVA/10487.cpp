#include<bits/stdc++.h>
using namespace std;
int a[1005];
int main()
{
    int n,m,cas=0;
    while(1)
    {
        scanf("%d",&n);
        if(!n)break;
        printf("Case %d:\n",++cas);
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        sort(a,a+n);
        scanf("%d",&m);
        while(m--)
        {
            int k;
            scanf("%d",&k);
            int ans=a[0]+a[1];
            int min_dif=ans-k;
            if(min_dif<0)min_dif=-min_dif;
            for(int i=0;i<n&&min_dif;i++)
            {
                int r=lower_bound(a,a+n,k-a[i])-a;
                for(int j=-1;j<=1;j++)
                {
                    int t=r+j;
                    if(t<0||t>=n||t==i)continue;
                    int sum=a[t]+a[i];
                    int dif=sum-k;
                    if(dif<0)dif=-dif;
                    if(dif<min_dif)
                    {
                        min_dif=dif;
                        ans=sum;
                    }
                }
            }
            printf("Closest sum to %d is %d.\n",k,ans);
        }
    }
    return 0;
}

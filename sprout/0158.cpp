//高棕櫚農場2
//0/1背包
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        int v[1005][105]={0};
        while(n--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            for(int i=m;i>=a;i--)
            {
                for(int j=k;j>0;j--)
                {
                    v[i][j]=max(v[i][j],v[i-a][j-1]+b);
                }
            }
        }
        int ans=0;
        for(int i=k;i>0;i--)
        {
            if(v[m][k]>ans)ans=v[m][k];
        }
        printf("%d\n",ans);
    }
    return 0;
}

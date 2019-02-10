#include<stdio.h>
#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;
int main()
{
    int n,m;
    while(scanf("%d%d",&m,&n)==2)
    {
        if(!m&&!n)break;
        int a[105][105];
        memset(a,0,sizeof(a));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
                if(a[i][j]==0)
                {
                    a[i][j]=a[i][j-1]+1;
                }
                else a[i][j]=0;
            }
        }
        int ans=0;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                int area=0;
                int len=a[i][j];
                int h;
                for(h=i;h>0&&a[h][j];h--)
                {
                    len=min(a[h][j],len);
                    area=len*(i-h+1);
                    ans=max(ans,area);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

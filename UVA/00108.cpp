//O(N^4)
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int a[105][105];
        int m[105][105];
        memset(a,0,sizeof(a));
        memset(m,0,sizeof(m));
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                scanf("%d",&a[i][j]);
                a[i][j]+=a[i][j-1];
                m[i][j]=a[i][j]+m[i-1][j];
            }
        }
        int ans=0;
        for(int xi=0; xi<n; xi++)
        {
            for(int xj=xi+1; xj<=n; xj++)
            {
                for(int yi=0; yi<n; yi++)
                {
                    for(int yj=yi+1; yj<=n; yj++)
                    {
                        int A=m[xj][yj]-m[xi][yj]-m[xj][yi]+m[xi][yi];
                        if(A>ans)ans=A;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
//O(N^3)
#include<stdio.h>
#include<iostream>
using namespace std;
#define maxn 105
int a[maxn][maxn];
int sum[maxn][maxn];
int n;
int main()
{
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++)
        {
            sum[i][0]=0;
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&a[i][j]);
                sum[i][j]=sum[i][j-1]+a[i][j];
            }
        }
        int ans=a[1][1];
        for(int i=1;i<=n;i++)
        {
            for(int j=i;j<=n;j++)
            {
                int area=0;
                for(int k=1;k<=n;k++)
                {
                    if(area<0)area=0;
                    area+=sum[k][j]-sum[k][i-1];
                    ans=max(ans,area);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

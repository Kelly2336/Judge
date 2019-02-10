//慘字道路規劃
//APSP
//Floyd-Warshall
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int d[505][505];
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            scanf("%d",&d[i][j]);
    int ans[505];
    memset(ans,0,sizeof(ans));
    for(int k=1; k<=n; k++)
        for(int i=1; i<=n; i++)
            for(int j=0; j<=n; j++)
            {
                if(d[i][k]!=-1&&d[k][j]!=-1)
                    if(d[i][j]==-1||d[i][j]>d[i][k]+d[k][j])
                        d[i][j]=d[i][k]+d[k][j];
                if(i<=k&&j<=k&&ans[k]!=-1)
                    if(d[i][j]==-1||d[i][j]>ans[k])
                        ans[k]=d[i][j];
            }
    for(int i=1; i<n; i++)
        printf("%d ",ans[i]);
    printf("%d\n",ans[n]);
    return 0;
}

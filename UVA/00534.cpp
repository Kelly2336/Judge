//SSSP
//Dijkstra
#include<stdio.h>
#include<iostream>
#include<cmath>
#include<string.h>
#define INF 200000
using namespace std;
inline double Dis(int x1,int y1,int x2,int y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
    int n;
    int cas=1;
    int x[210],y[210];
    double w[210][210];
    double d[210];
    bool visit[210];
    while(1)
    {
        scanf("%d",&n);
        if(!n)break;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
            w[i][i]=0;
            for(int j=1;j<i;j++)
            {
                w[i][j]=Dis(x[i],y[i],x[j],y[j]);
                w[j][i]=w[i][j];
            }
        }
        memset(visit,0,sizeof(visit));
        for(int i=1;i<=n;i++)d[i]=INF;
        d[1]=0;
        for(int r=n-1;r>=1;r--)
        {
            int mi;
            double MIN=INF;
            for(int i=1;i<=n;i++)
            {
                if(!visit[i]&&d[i]<MIN)
                {
                    MIN=d[i];
                    mi=i;
                }
            }
            visit[mi]=true;
            for(int i=1;i<=n;i++)
            {
                d[i]=min(max(d[mi],w[mi][i]),d[i]);
            }
        }
        printf("Scenario #%d\n",cas);
        printf("Frog Distance = %.3lf\n\n",d[2]);
        cas++;
    }
    return 0;
}

//10147
//MST
//Kruskal
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;
#define maxn 760
#define maxe 400000

int n,m;
int p[maxn];
int h[maxn];
int x[maxn];
int y[maxn];

struct Edge
{
    int a,b;
    int w;
}E[maxe];

bool operator<(Edge e1,Edge e2)
{
    return e1.w<e2.w;
}

inline int dis(int x1,int y1,int x2,int y2)
{
    return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

void init()
{
    for(int i=1;i<=n;i++)
    {
        p[i]=i;
        h[i]=1;
    }
}
int Find(int x)
{
    if(p[x]!=x)p[x]=Find(p[x]);
    return p[x];
}

void uni(int x,int y)
{
    int px=Find(x);
    int py=Find(y);
    if(h[px]<h[py])p[px]=py;
    else if(h[px]>h[py])p[py]=px;
    else
    {
        p[px]=py;
        h[py]++;
    }
}

int main()
{
    while(scanf("%d",&n)==1)
    {
        int ei=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&x[i],&y[i]);
            for(int j=1;j<i;j++)
            {
                E[ei].a=j;
                E[ei].b=i;
                E[ei].w=dis(x[i],y[i],x[j],y[j]);
                ei++;
            }
        }
        sort(E,E+ei);
        init();
        int cnt=0;
        scanf("%d",&m);
        while(m--)
        {
            int v,u;
            scanf("%d%d",&v,&u);
            if(Find(v)!=Find(u))
            {
                cnt++;
                uni(v,u);
            }
        }
        ei=0;
        double ans=0;
        for(;cnt<n-1;cnt++)
        {
            while(Find(E[ei].a)==Find(E[ei].b))ei++;
            uni(E[ei].a,E[ei].b);
            ans+=sqrt(E[ei].w);
            ei++;
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}

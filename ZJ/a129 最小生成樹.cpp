//Minimum Spanning Tree
//Kruskal's Algorithm
#include<stdio.h>
#include<algorithm>
using namespace std;
#define maxn 100005
#define maxm 200005
int n,m;
struct Edge
{
    int a,b,w;
} e[maxm];
bool operator<(Edge e1,Edge e2)
{
    return e1.w<e2.w;
}
int p[maxn];
int sz[maxn];
int init()
{
    for(int i=0; i<n; i++)
    {
        p[i]=i;
        sz[i]=1;
    }
}
int f(int x)//find x's parent
{
    if(x!=p[x])p[x]=f(p[x]);
    return p[x];
}
void u(int x,int y)//union
{
    if(sz[x]>sz[y])
    {
        int t=x;
        x=y;
        y=t;
    }
    p[f(x)]=f(y);
    sz[y]+=sz[x];
}
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=0; i<m; i++)
            scanf ("%d%d%d",&e[i].a,&e[i].b,&e[i].w);
        sort(e,e+m);
        init();
        int i,j;
        long long int sum=0;
        for(i=0,j=0; j<m; j++)
        {
            if(f(e[j].a)==f(e[j].b))continue;
            sum+=e[j].w;
            u(e[j].a,e[j].b);
            i++;
        }
        if(i==n-1)printf("%lld\n",sum);
        else printf("-1\n");
    }
    return 0;
}

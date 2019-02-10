#include<stdio.h>
#include<cstring>
#include<iostream>
using namespace std;

int G[105][105];
int m,n;
int c[105];
int topo[105];
int t;

bool dfs(int u)
{
    c[u]=-1;
    for(int v=1;v<=n;v++)
    {
        if(G[u][v])
        {
            if( c[v]==-1 )return false;//¦³¦VÀô
            else if( c[v]==0 && !dfs(v) )return false;
        }
    }

    c[u]=1;
    topo[--t]=u;
    return true;
}

bool toposort()
{
    t=n;
    memset(c,0,sizeof(c));
    for(int u=1;u<=n;u++)
    {
        if(!c[u])
            if(!dfs(u))
                return false;
    }
    return true;
}

int main()
{
    while(1)
    {
        scanf("%d%d",&n,&m);
        if(!n&&!m)break;
        memset(G,0,sizeof(G));
        for(int i=0;i<m;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u][v]=1;
        }
        if(toposort())
        {
            for(int i=0;i<n-1;i++)
            {
                printf("%d ",topo[i]);
            }
            printf("%d",topo[n-1]);
        }
        else printf("0");
        cout<<endl;
    }
    return 0;
}

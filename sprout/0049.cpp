//It's my ____ in the box
//DFS
#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
vector<int> child[100005];
int visit[100005];
int v[100005];

void dfs(int u)
{
    visit[u]=1;
    v[u]=1;
    int sz=child[u].size();
    for(int i=0;i<sz;i++)
    {
        int t=child[u][i];
        if(!visit[t])dfs(t);
        v[u]+=v[t];
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n;i++)child[i].clear();
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            child[x].push_back(y);
        }
        memset(visit,0,sizeof(visit));
        for(int i=1;i<=n;i++)
        {
            if(!visit[i])dfs(i);
        }
        int q;
        scanf("%d",&q);
        while(q--)
        {
            int x;
            scanf("%d",&x);
            printf("%d\n",v[x]);
        }
    }
    return 0;
}

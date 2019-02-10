//樹重心
//dfs
#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
vector<int> v[100005];
int child[100005];
bool visit[100005];
int n;
int ans;
int MIN;
void dfs(int u,int f)
{
    int w=0;
    int sz=v[u].size();
    child[u]=1;
    for(int i=0;i<sz;i++)
    {
        int t=v[u][i];
        if(t==f)continue;
        if(!visit[t])
        {
            visit[t]=1;
            dfs(t,u);
        }
        child[u]+=child[t];
        if(child[t]>w)w=child[t];
    }
    if((n-child[u])>w)w=n-child[u];
    if(w<MIN)
    {
        MIN=w;
        ans=u;
    }
    else if(w==MIN&&ans>u)ans=u;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)v[i].clear();
        for(int i=1;i<n;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        memset(visit,0,sizeof(visit));
        ans=0;
        MIN=n;
        visit[0]=1;
        dfs(0,-1);
        printf("%d\n",ans);
    }
    return 0;
}

#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
int visit[10010];
vector<int> nt[10010];

int fall;

void dfs(int i)
{
    if(visit[i])return;
    visit[i]=1;
    fall++;
    int sz=nt[i].size();
    for(int k=0;k<sz;k++)
    {
        dfs(nt[i][k]);
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,l;
        scanf("%d%d%d",&n,&m,&l);
        memset(visit,0,sizeof(visit));
        for(int i=0;i<=n;i++)nt[i].clear();
        fall=0;
        visit[0]=1;
        for(int i=0;i<m;i++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            nt[x].push_back(y);
        }
        for(int i=0;i<l;i++)
        {
            int t;
            scanf("%d",&t);
            dfs(t);
        }
        printf("%d\n",fall);
    }
    return 0;
}

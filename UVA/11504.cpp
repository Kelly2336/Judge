//SCC
#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
#define maxn 100005
bool visit[maxn]={0};
vector<int> v[maxn];
vector<int> topo;
void dfs1(int x)
{
	visit[x]=true;
	int sz=v[x].size();
	for(int i=0;i<sz;i++)
	{
		int xx=v[x][i];
		if(!visit[xx])dfs1(xx);
	}
	topo.push_back(x);
}
void dfs2(int x)
{
	visit[x]=true;
	int sz=v[x].size();
	for(int i=0;i<sz;i++)
	{
		int xx=v[x][i];
		if(!visit[xx])dfs2(xx);
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		memset(visit,0,sizeof(visit));
		for(int i=1;i<=n;i++)v[i].clear();
		topo.clear();
		while(m--)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
		}
		for(int i=1;i<=n;i++)
		{
			if(!visit[i])dfs1(i);
		}
		memset(visit,0,sizeof(visit));
		int ans=0;
		for(int i=n-1;i>=0;i--)
		{
			int u=topo[i];
			if(!visit[u])
			{
				ans++;
				dfs2(u);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

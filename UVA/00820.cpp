//無向邊
//max-flow min-cap
//Ford-Fulkerson
#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
#define maxn 105
#define INF 10000000
struct edge { int to,cap,rev; };
vector<edge> G[maxn];
bool visit[maxn];

void init(int n)
{
	for(int i=1;i<=n;i++)G[i].clear();
}

void add_edge(int from,int to,int cap)
{
	G[from].push_back((edge){to,cap,G[to].size()});
	G[to].push_back((edge){from,cap,G[from].size()-1});
}

int dfs(int v,int t,int f)
{
	if(v==t)return f;
	for(int i=0;i<G[v].size();i++)
	{
		edge &e=G[v][i];
		visit[v]=true;
		if(!visit[e.to] && e.cap>0)
		{
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0)
			{
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s,int t)
{
	int flow=0;
	while(1)
	{
		memset(visit,0,sizeof(visit));
		int f=dfs(s,t,INF);
		if(!f)return flow;
		flow+=f;
	}
}

int main()
{
	int cas=1;
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(!n)break;
		int s,t,m;
		scanf("%d%d%d",&s,&t,&m);
		init(n);
		while(m--)
		{
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			add_edge(a,b,c);
		}
		printf("Network %d\n",cas++);
		printf("The bandwidth is %d.\n\n",max_flow(s,t));
	}
	return 0;
}

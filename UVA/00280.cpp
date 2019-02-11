//BFS
#include <iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#define maxn 105
using namespace std;
int main()
{
	int n;
	while(scanf("%d",&n)==1&&n)
	{
		vector<int> v[maxn];
		while(1)
		{
			int x;
			scanf("%d",&x);
			if(!x)break;
			while(1)
			{
				int y;
				scanf("%d",&y);
				if(!y)break;
				v[x].push_back(y);
			}
		}
		int Q;
		scanf("%d",&Q);
		while(Q--)
		{
			int r;
			scanf("%d",&r);
			bool visit[maxn]={};
			queue<int> q;
			q.push(r);
			int ans=n;
			while(!q.empty())
			{
				int u=q.front();
				q.pop();
				for(int i=v[u].size()-1;i>=0;i--)
				{
					int uu=v[u][i];
					if(!visit[uu])
					{
						visit[uu]=true;
						q.push(uu);
						ans--;
					}
				}
			}
			printf("%d",ans);
			for(int i=1;i<=n&&ans;i++)
			{
				if(!visit[i])
				{
					printf(" %d",i);
					ans--;
				}
			}
			printf("\n");
		}
	}
	return 0;
}

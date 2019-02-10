#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define maxn 1005
#define INF 1e9
inline int p(int x,int y){return x*maxn+y;}
inline int x(int r){return r/maxn;}
inline int y(int r){return r%maxn;}
const short int dx[4]={0,0,1,-1};
const short int dy[4]={1,-1,0,0};
typedef pair<int,int> ii;
int main()
{
	int T;
	scanf("%d",&T);
	short int a[maxn][maxn];
	int sum[maxn][maxn];
	while(T--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				scanf("%hd",&a[i][j]);
				sum[i][j]=INF;
			}
		}
		priority_queue<ii,vector<ii>,greater<ii> > pq;
		sum[0][0]=a[0][0];
		pq.push(ii(sum[0][0],p(0,0)));
		while(!pq.empty())
		{
			ii t = pq.top();
			pq.pop();
			int tx = x(t.second);
			int ty = y(t.second);
			if( tx==n-1 && ty==m-1 )break;
			if(sum[tx][ty]!=t.first)continue;
			for(int i=0;i<4;i++)
			{
				int xx = tx+dx[i];
				int yy = ty+dy[i];
				if(xx<0||yy<0||xx>=n||yy>=m)continue;
				if(sum[xx][yy]>a[xx][yy]+sum[tx][ty])
				{
					sum[xx][yy] = a[xx][yy]+sum[tx][ty];
					pq.push(ii(sum[xx][yy],p(xx,yy)));
				}
			}
		}
		printf("%d\n",sum[n-1][m-1]);
	}
	return 0;
}

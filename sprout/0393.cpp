//百慕達三角洲
//Unweighted Graph
//SSSP
//Dijkstra
#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int,int> ii;
#define INF 100000000
char a[2010][2010];
int d[2010][2010];
int xi[4]={0,0,1,-1};
int yi[4]={1,-1,0,0};
int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++)
        scanf("%s",a[i]+1);
    for(int i=0;i<=N+1;i++)
        for(int j=0;j<=M+1;j++)
            d[i][j]=INF;
    int x1,x2,y1,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    priority_queue<ii,vector<ii>,greater<ii> > pq;
    while(!pq.empty())pq.pop();
    d[x1][y1]=0;
    pq.push(ii(0,x1*10000+y1));
    while(1)
    {
        int x;
        int y;
        while(1)
        {
            ii v=pq.top();
            x=v.second/10000;
            y=v.second%10000;
            pq.pop();
            if(d[x][y]==v.first)break;
        }
        if(x==x2&&y==y2)break;
        for(int i=0;i<4;i++)
        {
            int xx=x+xi[i];
            int yy=y+yi[i];
            if(xx<1||xx>N||yy<1||yy>M)continue;
            int r=1;
            if(a[xx][yy]=='#')r=0;
            if(d[xx][yy]>d[x][y]+r)
            {
                d[xx][yy]=d[x][y]+r;
                pq.push(ii(d[xx][yy],xx*10000+yy));
            }
        }
    }
    printf("%d\n",d[x2][y2]);
    return 0;
}

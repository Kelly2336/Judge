#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
using namespace std;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int ans=0;
        char a[105][105];
        memset(a,0,sizeof(a));
        for(int i=1;i<=n;i++)scanf("%s",&a[i][1]);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(a[i][j]!='1')continue;
                int visit[105][105];
                memset(visit,0,sizeof(visit));
                queue<int> qx,qy;
                qx.push(i);
                qy.push(j);
                visit[i][j]=1;
                bool three=false;
                while(!three&&!qx.empty())
                {
                    int x=qx.front();qx.pop();
                    int y=qy.front();qy.pop();
                    for(int k=0;k<4;k++)
                    {
                        int xx=x+dx[k],yy=y+dy[k];
                        if(a[xx][yy]&&!visit[xx][yy])
                        {
                            visit[xx][yy]=visit[x][y]+1;
                            qx.push(xx);qy.push(yy);
                        }
                        if(a[xx][yy]=='3')
                        {
                            three=true;
                            ans=max(ans,visit[xx][yy]);
                            break;
                        }
                    }
                }
            }
        }
        printf("%d\n",ans-1);
    }
    return 0;
}

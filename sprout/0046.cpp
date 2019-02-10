//染色遊戲
//BFS
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
using namespace std;

int B[1005][1005];
int Y[1005][1005];
int R[1005][1005];
int graph[1005][1005];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    int n;
    while(scanf("%d",&n)==1)
    {
        
        queue<int>BX,BY,YX,YY,RX,RY;
        memset(B,0,sizeof(B));//2
        memset(Y,0,sizeof(Y));//5
        memset(R,0,sizeof(R));//9
        memset(graph,0,sizeof(graph));
        for(int i=0; i<3; i++)
        {
            char c;
            int x,y;
            cin>>c>>x>>y;
            if(c=='B')
            {
                B[x][y]=1;
                graph[x][y]+=2;
                BX.push(x);
                BY.push(y);
            }
            if(c=='Y')
            {
                Y[x][y]=1;
                graph[x][y]+=5;
                YX.push(x);
                YY.push(y);
            }
            if(c=='R')
            {
                R[x][y]=1;
                graph[x][y]+=9;
                RX.push(x);
                RY.push(y);
            }
        }
        char f;
        int id=0;
        cin>>f;
        char color[8]="RYBOPGD";
        int s[7]= {9,5,2,14,11,7,16};
        int sum=0;
        int ans=0;
        for(int h=0; h<7; h++)
        {
            if(f==color[h])
            {
                id=s[h];
                break;
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(graph[i][j]==id)sum++;
            }
        }
        if(sum>ans)ans=sum;
        for(int i=1; i<=n; i++)
        {
            /*
            printf("time %d:\n",i);
            for(int ii=n-1;ii>=0;ii--)
            {
                for(int jj=0;jj<n;jj++)
                {
                    printf("%2d ",graph[jj][ii]);
                }
                printf("\n");
            }
            */
            while(1)
            {
                if(BX.empty())break;
                int x=BX.front();
                int y=BY.front();
                if(B[x][y]>i)break;
                BX.pop();
                BY.pop();
                for(int j=-1; j<=1; j++)
                {
                    int xx=x+j;
                    if(xx<0||xx>=n)continue;
                    for(int k=-1; k<=1; k++)
                    {
                        int yy=y+k;
                        if(yy<0||yy>=n)continue;
                        if(B[xx][yy]==0)
                        {
                            if(graph[xx][yy]==id)sum--;
                            graph[xx][yy]+=2;
                            BX.push(xx);
                            BY.push(yy);
                            B[xx][yy]=B[x][y]+1;
                            if(graph[xx][yy]==id)sum++;
                        }
                    }
                }
            }
            while(1)
            {
                if(YX.empty())break;
                int x=YX.front();
                int y=YY.front();
                if(Y[x][y]>i)break;
                YY.pop();
                YX.pop();
                for(int j=-1; j<=1; j++)
                {
                    int xx=x+j;
                    if(xx<0||xx>=n)continue;
                    for(int k=-1; k<=1; k++)
                    {
                        int yy=y+k;
                        if(yy<0||yy>=n)continue;
                        if(Y[xx][yy]==0)
                        {
                            if(graph[xx][yy]==id)sum--;
                            graph[xx][yy]+=5;
                            YX.push(xx);
                            YY.push(yy);
                            Y[xx][yy]=Y[x][y]+1;
                            if(graph[xx][yy]==id)sum++;
                        }
                    }
                }
            }
            while(1)
            {
                if(RX.empty())break;
                int x=RX.front();
                int y=RY.front();
                if(R[x][y]>i)break;
                RX.pop();
                RY.pop();
                for(int j=-1; j<=1; j++)
                {
                    int xx=x+j;
                    if(xx<0||xx>=n)continue;
                    for(int k=-1; k<=1; k++)
                    {
                        int yy=y+k;
                        if(yy<0||yy>=n)continue;
                        if(R[xx][yy]==0)
                        {
                            if(graph[xx][yy]==id)sum--;
                            graph[xx][yy]+=9;
                            RX.push(xx);
                            RY.push(yy);
                            R[xx][yy]=R[x][y]+1;
                            if(graph[xx][yy]==id)sum++;
                        }
                    }
                }
            }
            if(sum>ans)ans=sum;
        }
        printf("%d\n",ans);
    }
    }
    return 0;
}

#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int dx[6]={0,0,1,-1,0,0};
int dy[6]={1,-1,0,0,0,0};
int dz[6]={0,0,0,0,1,-1};
int main()
{
    int l,r,c;
    while(scanf("%d%d%d",&l,&r,&c)>=3&&l&&r&&c)
    {
        int m[35][35][35];
        char s[35];
        memset(m,-1,sizeof(m));
        int ei,ej,ek;
        queue<int> qx,qy,qz;
        for(int i=1;i<=l;i++)
        {
            for(int j=1;j<=r;j++)
            {
                scanf(" %s",s+1);
                for(int k=1;k<=c;k++)
                {
                    if(s[k]=='.')m[i][j][k]=0;
                    else if(s[k]=='S'){qx.push(i);qy.push(j);qz.push(k);m[i][j][k]=1;}
                    else if(s[k]=='E'){ei=i;ej=j;ek=k;m[i][j][k]=0;}
                }
            }
        }
        //BFS
        while(!qx.empty()&&!m[ei][ej][ek])
        {
            int x=qx.front();qx.pop();
            int y=qy.front();qy.pop();
            int z=qz.front();qz.pop();
            for(int di=0;di<6;di++)
            {
                int xx=x+dx[di],yy=y+dy[di],zz=z+dz[di];
                if(m[xx][yy][zz])continue;
                m[xx][yy][zz]=m[x][y][z]+1;
                qx.push(xx);qy.push(yy);qz.push(zz);
            }
        }
        if(m[ei][ej][ek])printf("Escaped in %d minute(s).\n",m[ei][ej][ek]-1);
        else printf("Trapped!\n");
    }
    return 0;
}

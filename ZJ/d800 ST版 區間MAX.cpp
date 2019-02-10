//2D RMQ
//Sparse Table
#include<bits/stdc++.h>
using namespace std;
#define maxn 505
#define lgn 9
int ST[lgn][maxn][lgn][maxn];
void build(int n,int m)//O(N*lgN*M*lgM)
{
    //先把每條垂直的建起來
    for(int i=1;i<=m;i++)
        for(int j=1;(1<<j)<=n;j++)
            for(int k=1;k+(1<<j)-1<=n;k++)
                ST[j][k][0][i]=max(ST[j-1][k][0][i],ST[j-1][k+(1<<(j-1))][0][i]);
    //沿著水平方向整合
    for(int i=0;(1<<i)<=n;i++)
        for(int j=1;j+(1<<i)-1<=n;j++)
            for(int k=1;(1<<k)<=m;k++)
                for(int q=1;q+(1<<k)-1<=m;q++)
                    ST[i][j][k][q]=max(ST[i][j][k-1][q],ST[i][j][k-1][q+(1<<(k-1))]);
}
int query(int x1,int y1,int x2,int y2)//O(1)
{
    int xx=__lg(x2-x1+1);
    int yy=__lg(y2-y1+1);
    return max(max(ST[xx][x1][yy][y1],ST[xx][x2-(1<<xx)+1][yy][y1]),max(ST[xx][x1][yy][y2-(1<<yy)+1],ST[xx][x2-(1<<xx)+1][yy][y2-(1<<yy)+1]));
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&ST[0][i][0][j]);
        build(n,m);
        int Q;
        scanf("%d",&Q);
        while(Q--)
        {
            int x1,x2,y1,y2;
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            printf("%d\n",query(x1,y1,x2,y2));
        }
    }
    return 0;
}

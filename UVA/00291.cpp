#include<stdio.h>
#include<string.h>
using namespace std;
bool visit[6][6];
bool a[6][6]=
{
    0,0,0,0,0,0,
    0,0,1,1,0,1,
    0,1,0,1,0,1,
    0,1,1,0,1,1,
    0,0,0,1,0,1,
    0,1,1,1,1,0
};
int ans[9];
void solve(int u,int i)
{
    if(i==9)
    {
        for(int t=0;t<9;t++)
        {
            printf("%d",ans[t]);
        }
        printf("\n");
    }
    for(int v=1;v<=5;v++)
    {
        if(a[u][v]&&!visit[u][v])
        {
            visit[u][v]=true;
            visit[v][u]=true;
            ans[i]=v;
            solve(v,i+1);
            visit[u][v]=false;
            visit[v][u]=false;
        }
    }
}
int main()
{
    memset(visit,0,sizeof(visit));
    ans[0]=1;
    solve(1,1);
    return 0;
}

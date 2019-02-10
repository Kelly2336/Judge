#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
#define MAXN 10010
vector<int> G[MAXN];
int dp[MAXN][3];
bool visit[MAXN];
int n;
void dfs(int i,int f)
{
    if(visit[i])return;
    visit[i]=true;
    dp[i][0]=1;
    dp[i][1]=0;
    dp[i][2]=MAXN;
    int sz=G[i].size();
    /*if(sz==1 && f!=0)//leaf
    {
        dp[i][2]=-MAXN;
        return;
    }*/
    for(int j=0;j<sz;j++)
    {
        int t=G[i][j];
        if(t==f)continue;
        dfs(t,i);
        dp[i][0]+=min(dp[t][0],dp[t][1]);
        dp[i][1]+=dp[t][2];
    }
    for(int j=0;j<sz;j++)
    {
        int t=G[i][j];
        if(t==f)continue;
        dp[i][2]=min(dp[i][2],dp[i][1]-dp[t][2]+dp[t][0]);
    }
}
int main()
{
    while(1)
    {
        int r;
        scanf("%d",&n);
        for(int i=0;i<=n;i++)G[i].clear();
        memset(visit,0,sizeof(visit));
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n-1;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        scanf("%d",&r);
        dfs(1,0);
        /*
        cout<<endl;
        for(int i=1;i<=n;i++)
        {
            printf("%d:%6d %6d %6d",i,dp[i][0],dp[i][1],dp[i][2]);
            cout<<endl;
        }
        */
        printf("%d",min(dp[1][0],dp[1][2]));
        cout<<endl;
        if(r==-1)break;
    }
    return 0;
}

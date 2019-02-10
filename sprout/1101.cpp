//哪裡有卦，哪裡就有源
//dfs
#include<stdio.h>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

vector<int> G[100050];
int visit[100050];
bool normal;

void dfs(int i)
{
    int sz=G[i].size();
    for(int j=0; j<sz && normal; j++)
    {
        int t=G[i][j];
        if(!visit[t])
        {
            visit[t]=visit[i]%2+1;
            dfs(t);
        }
        else if(visit[t]==visit[i])
        {
            normal=false;
            break;
        }
    }
}

int main()
{
    int n,m;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        scanf("%d",&m);
        for(int i=0; i<n; i++)G[i].clear();
        memset(visit,0,sizeof(visit));
        for(int i=0; i<m; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        normal=true;
        for(int i=0; i<n && normal; i++)
        {
            if(!visit[i])
            {
                visit[i]=1;
                dfs(i);
            }
        }
        if(normal)printf("NORMAL.\n");
        else printf("RAINBOW.\n");
    }
    return 0;
}

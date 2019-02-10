//bicolor
//bfs
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
vector<int> v[210];
int main()
{
    int n,m;
    while(1)
    {
        scanf("%d",&n);
        if(!n)break;
        for(int i=0;i<n;i++)v[i].clear();
        scanf("%d",&m);
        int a,b;
        while(m--)
        {
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int color[210];
        memset(color,0,sizeof(color));
        queue<int> q;
        while(!q.empty())q.pop();
        q.push(0);
        color[0]=1;
        bool success=true;
        while(!q.empty()&&success)
        {
            int u=q.front();
            q.pop();
            for(int i=v[u].size()-1;i>=0;i--)
            {
                int uu=v[u][i];
                if(!color[uu])
                {
                    color[uu]=-color[u];
                    q.push(uu);
                }
                else if(color[uu]==color[u])
                {
                    success=false;
                    break;
                }
            }
        }
        if(success)printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define maxn 30005
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int ans=0;
        vector<int> v[maxn];
        bool visit[maxn]={0};
        while(m--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            v[b].push_back(a);
        }
        int res=n;
        for(int i=1;ans<res;i++)
        {
            if(visit[i])continue;
            int now=1;
            queue<int> q;
            q.push(i);
            visit[i]=true;
            while(!q.empty()) //BFS
            {
                int u=q.front();
                q.pop();
                for(int j=v[u].size()-1;j>=0;j--)
                {
                    int uu=v[u][j];
                    if(!visit[uu])
                    {
                        visit[uu]=true;
                        q.push(uu);
                        now++;
                    }
                }
            }
            res-=now;
            ans=max(ans,now);
        }
        printf("%d\n",ans);
    }
    return 0;
}

//topological sort
//因為找字典序最小，所以用priority_queue而不是用queue
#include<stdio.h>
#include<string.h>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    int n,m;
    vector<int> v[105];
    int sz[105];	//出度
    int d[105];		//入度
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=0;i<n;i++)
            v[i].clear();
        memset(sz,0,sizeof(sz));
        memset(d,0,sizeof(d));
        int a,b;
        while(m--)
        {
            scanf("%d%d",&a,&b);
            v[a].push_back(b);
            sz[a]++;
            d[b]++;
        }
        priority_queue<int,vector<int>,greater<int> > pq;
        while(!pq.empty())pq.pop();
        for(int i=0;i<n;i++)
        {
            if(!d[i])pq.push(i);
        }
        while(!pq.empty())
        {
            int u=pq.top();
            pq.pop();
            printf("%d ",u);
            for(int i=0;i<sz[u];i++)
            {
                int uu=v[u][i];
                d[uu]--;
                if(!d[uu])pq.push(uu);
            }
        }
        printf("\n");
    }
    return 0;
}

//可魚果運輸問題
//SSSP
//Dijkstra
#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
#define MAXN 105
#define INF 1e16
typedef long long int LL;
typedef pair<LL,int> ii;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N,M,S,E,F;
        scanf("%d%d%d%d%d",&N,&M,&S,&E,&F);
        vector<ii> v[MAXN];
        for(int i=0; i<=N; i++)v[i].clear();
        while(M--)
        {
            int A,B,D;
            LL C,CC;
            scanf("%d%d%lld%d%lld",&A,&B,&C,&D,&CC);
            LL cost=C*F;
            if(F>D)cost=(F-D)*CC+C*D;
            v[A].push_back(ii(cost,B));
        }
        LL d[MAXN];
        fill(d,d+N+1,INF);
        priority_queue<ii,vector<ii>,greater<ii> > pq;
        while(!pq.empty())pq.pop();
        d[S]=0;
        pq.push(ii(0,S));
        for(int i=1; i<N; i++)
        {
            int u;
            while(1)
            {
                ii e=pq.top();
                pq.pop();
                if(d[e.second]==e.first)
                {
                    u=e.second;
                    break;
                }
            }
            int sz=v[u].size();
            for(int j=0; j<sz; j++)
            {
                ii x=v[u][j];
                LL w=x.first;
                int uu=x.second;
                if(d[uu]>d[u]+w)
                {
                    d[uu]=d[u]+w;
                    pq.push(ii(d[uu],uu));
                }
            }
        }
        printf("%lld\n",d[E]);
    }
    return 0;
}

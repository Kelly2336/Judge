#include<stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define max_n 200005
#define INF 1e15
typedef long long LL;
typedef pair<LL,int> li;
typedef pair<int,int> ii;
LL d1[max_n];
LL dn[max_n];
vector<ii> v1[max_n];
vector<ii> vn[max_n];
int main()
{
    int N,M,Q;
    scanf("%d%d%d",&N,&M,&Q);
    for(int i=0;i<=N;i++)
    {
        v1[i].clear();
        vn[i].clear();
    }
    int a,b,w;
    while(M--)
    {
        scanf("%d%d%d",&a,&b,&w);
        v1[a].push_back(ii(b,w));
        vn[b].push_back(ii(a,w));
    }
    priority_queue<li,vector<li>,greater<li> > pq1,pqn;
    while(!pq1.empty())pq1.pop();
    while(!pqn.empty())pqn.pop();
    fill(d1,d1+N+1,INF);
    fill(dn,dn+N+1,INF);
    d1[1]=0;
    dn[N]=0;
    pq1.push(li(0,1));
    pqn.push(li(0,N));
    for(int r=N-1;r>0&&!pq1.empty();r--)
    {
        int u;
        while(!pq1.empty())
        {
            li y=pq1.top();
            pq1.pop();
            u=y.second;
            if(d1[u]==y.first)break;
        }
        int sz=v1[u].size();
        for(int j=0;j<sz;j++)
        {
            int uu=v1[u][j].first;
            int ww=v1[u][j].second;
            if(d1[uu]>d1[u]+ww)
            {
                d1[uu]=d1[u]+ww;
                pq1.push(li(d1[uu],uu));
            }
        }
    }
    for(int r=N-1;r>0&&!pqn.empty();r--)
    {
        int u;
        while(!pqn.empty())
        {
            li y=pqn.top();
            pqn.pop();
            u=y.second;
            if(dn[u]==y.first)break;
        }
        int sz=vn[u].size();
        for(int j=0;j<sz;j++)
        {
            int uu=vn[u][j].first;
            int ww=vn[u][j].second;
            if(dn[uu]>dn[u]+ww)
            {
                dn[uu]=dn[u]+ww;
                pqn.push(li(dn[uu],uu));
            }
        }
    }
    while(Q--)
    {
        int c,d;
        scanf("%d%d",&c,&d);
        printf("%lld\n",min(d1[N],d1[c]+dn[d]+1));
    }
    return 0;
}

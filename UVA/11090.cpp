#include<bits/stdc++.h>
using namespace std;
#include<cfloat> //for DBL_MAX
#define MAXN 55
int dp[MAXN][MAXN]; // 1-base,O(NM)
vector<tuple<int,int,int>> edge;
double mmc(int n){ //allow negative weight
    const int INF = 0x3f3f3f3f;
    for(int t=0; t<n; ++t){
        memset(dp[t+1],0x3f,sizeof(dp[t+1]));
        for(const auto &e:edge) {
            int u,v,w;
            tie(u,v,w) = e;
            dp[t+1][v] = min(dp[t+1][v],dp[t][u]+w);
        }
    }
    double res = DBL_MAX;
    for(int u=1; u<=n; ++u) {
        if(dp[n][u]==INF) continue;
        double val = -DBL_MAX;
        for(int t=0;t<n;++t)
            val = max(val,(dp[n][u]-dp[t][u])*1.0/(n-t));
        res = min(res,val);
    }
    return res;
}
int main()
{
    int N;
    scanf("%d",&N);
    for(int cas = 1; cas<=N; cas++)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        edge.clear();
        while(m--)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            edge.push_back(make_tuple(a,b,c));
        }
        double ans = mmc(n);
        printf("Case #%d: ",cas);
        if(ans>510000000.0)
            printf("No cycle found.\n");
        else
            printf("%.2f\n", ans);
    }
    return 0;
}

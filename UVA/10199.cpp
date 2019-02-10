//connected component
//dfs
#include<bits/stdc++.h>
using namespace std;
#define maxn 105
int n;
vector<int> v[maxn];
int visit[maxn];
int low[maxn];
vector<string> ans;
string name[maxn];
int t;
void dfs(int p,int i)
{
    visit[i]=low[i]=++t;
    int sz=v[i].size();
    int child=0;
    bool ap=false;
    for(int k=0;k<sz;k++)
    {
        int u=v[i][k];
        if(visit[u])//back edge
        {
            low[i]=min(visit[u],low[i]);
        }
        else//tree edge
        {
            child++;
            dfs(i,u);
            low[i]=min(low[i],low[u]);
            if((i==p&&child>1)||(i!=p&&low[u]>=visit[i]))ap=true;
        }
    }
    if(ap)ans.push_back(name[i]);
}
int main()
{
    int cas=0;
    while(1)
    {
        scanf("%d",&n);
        if(!n)break;
        map<string,int> m;
        for(int i=0; i<n; i++)
        {
            cin>>name[i];
            m[name[i]]=i;
        }
        int r;
        scanf("%d",&r);
        for(int i=0; i<n; i++)v[i].clear();
        while(r--)
        {
            string a,b;
            cin>>a>>b;
            int ai=m[a];
            int bi=m[b];
            v[ai].push_back(bi);
            v[bi].push_back(ai);
        }
        memset(visit,0,sizeof(visit));
        ans.clear();
        t=0;
        for(int i=0;i<n;i++)
        {
            if(!visit[i])dfs(i,i);
        }
        int sz=ans.size();
        if(cas)printf("\n");
        printf("City map #%d: %d camera(s) found\n",++cas,sz);
        sort(ans.begin(),ans.end());
        for(int i=0;i<sz;i++)cout<<ans[i]<<endl;
    }
    return 0;
}

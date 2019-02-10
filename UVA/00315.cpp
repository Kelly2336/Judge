#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
#include<sstream>
using namespace std;
#define maxn 105
int n;
vector<int> v[maxn];
int visit[maxn];//time of dfs
int low[maxn];
int ans;
int t;
void dfs(int p,int i)
{
    visit[i]=low[i]=++t;
    int child=0;
    int sz=v[i].size();
    bool ap=false;
    for(int k=0;k<sz;k++)
    {
        int u=v[i][k];
        if(u==p)continue;
        if(visit[u])//back edge
        {
            //找最高的祖先
            low[i]=min(low[i],visit[u]);
        }
        else//tree edge
        {
            child++;
            dfs(i,u);
            //找最高的祖先
            low[i]=min(low[i],low[u]);
            if(low[u]>=visit[i])ap=true;
        }
    }
    if( (i==p&&child>1) || (i!=p&&ap) )ans++;
}
int main()
{
    while(1)
    {
        //input
        scanf("%d",&n);
        if(!n)break;
        for(int i=1;i<=n;i++)v[i].clear();
        while(1)
        {
            int a,b;
            scanf("%d",&a);
            if(!a)break;
            string s;
            stringstream ss;
            getline(cin,s);
            ss.clear();
            ss.str(s);
            while(ss>>b)
            {
                v[a].push_back(b);
                v[b].push_back(a);
            }
        }
        //connected component by dfs
        ans=0;//Articulation Point
        t=0;//time
        memset(visit,0,sizeof(visit));
        for(int i=1;i<=n;i++)//以i為根
        {
            if(!visit[i])dfs(i,i);
        }
        printf("%d\n",ans);
    }
    return 0;
}

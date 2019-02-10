#include<stdio.h>
#include<set>
#include<vector>
using namespace std;

vector<int>graph[100000];
set<int> leaf;
bool tree;

void bfs(int v)
{
    for(int i=0;i<graph[v].size();i++)
    {
        int z=graph[v][i];
        if(leaf.count(z)==1)
        {
            leaf.erase(z);
            bfs(z);
        }
        else tree=false;
    }
}


int main()
{
    int cas=0;
    while(1)
    {
        int n=0;
        int i[10000];
        int j[10000];
        for(int q=0;q<100000;q++)graph[q].clear();
        tree=true;
        set<int> loot;
        loot.clear();
        leaf.clear();
        while(scanf("%d%d",&i[n],&j[n])==2)
        {
            if(i[n]<=0&&j[n]<=0)break;
            if(loot.count(i[n])==0)loot.insert(i[n]);
            if(leaf.count(j[n])==0)leaf.insert(j[n]);
            else tree=false;//2­Ó¥H¤W¤÷¿Ë
            graph[i[n]].push_back(j[n]);
            n++;
        }
        if(i[0]<0&&j[0]<0)break;
        cas++;
        if(i[0]==0&&j[0]==0)//0 0
        {
            printf("Case %d is a tree.\n",cas);
            continue;
        }
        if(!tree)
        {
            printf("Case %d is not a tree.\n",cas);
            continue;
        }
        for(int k=0;k<=n;k++)//§ä®Ú
        {
            if(loot.count(j[k])!=0)loot.erase(j[k]);
        }
        if(loot.size()!=1)tree=false;
        if(!tree)
        {
            printf("Case %d is not a tree.\n",cas);
            continue;
        }
        int v=*(loot.begin());
        bfs(v);
        if(leaf.size()>0)tree=false;
        if(tree)printf("Case %d is a tree.\n",cas);
        else printf("Case %d is not a tree.\n",cas);
    }
    return 0;
}

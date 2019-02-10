//Tarjan's algorithm
//LCA
#include<bits/stdc++.h>
using namespace std;
#define maxv 100
int LCA[maxv][maxv];//lowest common ancestor
vector<int> v[maxv];//adjacency lists
int p[maxv];//parent
bool visit[maxv];//false
int n;//the number of vertex
void init()//Union-Find tree
{
    for(int i=0;i<n;i++)
        p[i]=i;
}
int parent(int x)//find parent
{
    if(p[x]!=x)p[x]=parent(p[x]);
    return p[x];
}
int dfs(int u)
{
    visit[u]=true;
    for(int i=0;i<n;i++)
        if(visit[i])
            LCA[i][u]=LCA[u][i]=parent(i);
    for(int i=v[u].size()-1;i>=0;i--)
    {
        int uu=v[u][i];
        if(!visit[uu])
        {
            dfs(uu);
            p[uu]=u;
        }
    }
}
void Tarjan()
{
    init();
    dfs(0);
}
int main()
{
    int e,q;
    scanf("%d%d%d",&n,&e,&q);
    for(int i=0;i<e;i++)//read edge
    {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    Tarjan();
    while(q--)//query
    {
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",LCA[a][b]);
    }
    return 0;
}

/*
input:
8 7 5
0 1
1 2
1 3
2 4
2 5
4 6
4 7

6 7
6 5
6 3
4 3
7 3
output:
4
2
1
1
1
*/

//http://www.csie.ntnu.edu.tw/~u91029/Tree.html#5 演算法筆記

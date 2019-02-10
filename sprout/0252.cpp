//Counting Triangles
//根號+離線
#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;
int d[100005]= {0};
vector<int> v[100005];
int a[100005][2];
int adj[100005]= {0};
vector<int> ask[100005];
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int tri=0;
    for(int i=0; i<m; i++)
    {
        scanf("%d%d",&a[i][0],&a[i][1]);
        d[a[i][0]]++;
        d[a[i][1]]++;
        v[a[i][0]].push_back(a[i][1]);
        v[a[i][1]].push_back(a[i][0]);
    }
    int k=sqrt(m);
    int round=0;
    for(int u=0; u<n; u++)
    {
        if(d[u]>k)
        {
            round++;
            for(int r=0; r<d[u]; r++)
            {
                adj[v[u][r]]=round;
            }
            for(int mm=0; mm<m; mm++)
            {
                int u1=a[mm][0];
                int u2=a[mm][1];
                if(adj[u1]==round&&adj[u2]==round)
                {
                    tri++;
                }
            }
        }
        else
        {
            for(int i=0; i<d[u]; i++)
            {
                for(int j=i+1; j<d[u]; j++)
                {
                    ask[v[u][i]].push_back(v[u][j]);
                }
            }
        }
    }
    for(int u=0; u<n; u++)
    {
        int sz=ask[u].size();
        if(sz==0)continue;
        round++;
        for(int r=0; r<d[u]; r++)
        {
            adj[v[u][r]]=round;
        }
        for(int i=0; i<sz; i++)
        {
            if(adj[ask[u][i]]==round)tri++;
        }
    }
    printf("%d\n",tri/3);
    return 0;
}

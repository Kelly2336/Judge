#include<stdio.h>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

#define maxv 10005

int in_order[maxv],post_order[maxv],lch[maxv],rch[maxv];
int n;

int best_sum,best_u;


bool read_list(int *a)
{
    string s;
    if(!getline(cin,s))return false;
    stringstream ss;
    ss.clear();
    ss.str(s);
    n=0;
    int x;
    while(ss>>x)a[n++]=x;
    return (n>0);
}

int build(int L1,int R1,int L2,int R2)
{
    if(L1>R1)return 0;
    int root = post_order[R2];
    int p = L1;
    while(in_order[p] != root)p++;
    int cnt=p-L1;
    lch[root]=build( L1 , p-1 , L2 , L2+cnt-1 );
    rch[root]=build( p+1, R1, L2+cnt , R2-1 );
    return root;
}

void dfs(int u,int sum)
{
    sum+=u;

    if( !lch[u] && !rch[u] )
    {
        if( sum<best_sum || (sum==best_sum && u<best_u))
        {
            best_u=u;
            best_sum=sum;
        }
    }
    if(lch[u])dfs(lch[u],sum);
    if(rch[u])dfs(rch[u],sum);
}

int main()
{
    while(read_list(in_order))
    {
        read_list(post_order);
        build(0,n-1,0,n-1);
        best_sum = 1000000000;
        dfs(post_order[n-1],0);
        printf("%d\n",best_u);
    }
    return 0;
}

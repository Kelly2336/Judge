//RMQ
//Sparse Table
#include<bits/stdc++.h>
using namespace std;
#define maxn 500005
#define lgn 18
int a[maxn];
int ST[lgn][maxn];
void build(int n)//O(NlgN)
{
    for(int i=1;i<=n;i++)ST[0][i]=a[i];
    for(int i=1;(1<<i)<n;i++)
    {
        int k=n-(1<<i)+1;
        for(int j=1;j<=k;j++)
        {
            ST[i][j]=max(ST[i-1][j],ST[i-1][j+(1<<(i-1))]);
        }
    }
}
int query(int l,int r)//O(1)
{
    int k=__lg(r-l+1);//log2
    return max(ST[k][l],ST[k][r-(1<<k)+1]);
}
int main()
{
    int n,m;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    build(n);
    scanf("%d",&m);
    while(m--)
    {
        int l,r;
        scanf("%d%d",&l,&r);
        if(l>r){int t=l;l=r;r=t;}
        printf("%d\n",query(l,r));
    }
    return 0;
}

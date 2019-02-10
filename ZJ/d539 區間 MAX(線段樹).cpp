//RMQ
//fake segment tree
#include<stdio.h>
#include<iostream>
using namespace std;
#define maxn 500005
int a[maxn];
struct node
{
    int left,right;
    int data;
}tree[maxn*4];
void build(int l,int r,int i)
{
    tree[i].left=l;tree[i].right=r;
    if(l==r){tree[i].data=a[l];return;}
    int mid=(l+r)>>1;
    int li=i<<1;
    int ri=li|1;
    build(l,mid,li);
    build(mid+1,r,ri);
    tree[i].data=max(tree[li].data,tree[ri].data);
}
int query(int a,int b,int i)
{
    int l=tree[i].left,r=tree[i].right;
    if(l==a&&r==b)return tree[i].data;
    int li=i<<1;
    int ri=li|1;
    int mid=(l+r)>>1;
    if(b<=mid)return query(a,b,li);
    if(a>mid) return query(a,b,ri);
    return max(query(a,mid,li),query(mid+1,b,ri));
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    build(1,n,1);
    int m;
    scanf("%d",&m);
    while(m--)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        if(a>b){int t=a;a=b;b=t;}
        printf("%d\n",query(a,b,1));
    }
    return 0;
}

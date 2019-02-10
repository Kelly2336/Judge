//RMQ 練習(1)
//單點修改+區間查詢
#include<stdio.h>
#include<iostream>
using namespace std;

int a[1000005];
int N;

struct node
{
    int ll,rr;
    int v;
} tree[2000005];

void build(int l,int r,int i)
{
    tree[i].ll=l;
    tree[i].rr=r;
    if(l==r)
    {
        tree[i].v=a[l];
    }
    else
    {
        int mid=(l+r)/2;
        build(l,mid,i*2);
        build(mid+1,r,i*2+1);
        tree[i].v=min(tree[i*2].v,tree[i*2+1].v);
    }
}

void modify(int x,int y,int i)
{
    int l=tree[i].ll;
    int r=tree[i].rr;
    if(l==r)
    {
        tree[i].v=y;
    }
    else
    {
        int mid=(l+r)/2;
        if(x<=mid)modify(x,y,i*2);
        else modify(x,y,i*2+1);
        tree[i].v=min(tree[i*2].v,tree[i*2+1].v);
    }
}

int query(int l,int r,int i)
{
    int ll=tree[i].ll;
    int rr=tree[i].rr;
    if(ll==l&&rr==r)
    {
        return tree[i].v;
    }
    else
    {
        int mid=(ll+rr)/2;
        if(r<=mid)return query(l,r,i*2);
        else if(l>mid)return query(l,r,i*2+1);
        else return min(query(l,mid,i*2),query(mid+1,r,i*2+1));
    }
}

int main()
{
    int T;
    scanf("%d%d",&T,&N);
    for(int i=0; i<N; i++)scanf("%d",&a[i]);
    build(0,N-1,1);
    while(T--)
    {
        int q;
        scanf("%d",&q);
        if(q==1)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%d\n",query(l,r,1));
        }
        else
        {
            int x,y;
            scanf("%d%d",&x,&y);
            modify(x,y,1);
        }
    }
    return 0;
}

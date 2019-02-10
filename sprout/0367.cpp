//RMQ˙改
//線段樹
//區間查詢+區間加值
//Maximum
#include<stdio.h>
#include<iostream>
using namespace std;
int a[100005];

struct node
{
    int nl, nr;
    int v=0;
    int chg=0;
}t[400000];

void build(int l,int r,int i)
{
    t[i].nl=l;
    t[i].nr=r;
    if(l==r)t[i].v=a[l];
    else
    {
        int mid=(l+r)/2;
        build(l,mid,i*2);
        build(mid+1,r,i*2+1);
        t[i].v=max(t[i*2].v,t[i*2+1].v);
    }
}

int query(int ql,int qr,int i)
{
    int l=t[i].nl;
    int r=t[i].nr;
    int mid=(l+r)/2;
    if(l==ql&&r==qr)return t[i].v+t[i].chg;
    else
    {
        if(qr<=mid)return query(ql,qr,i*2)+t[i].chg;
        else if(ql>mid)return query(ql,qr,i*2+1)+t[i].chg;
        else return max(query(ql,mid,i*2),query(mid+1,qr,i*2+1))+t[i].chg;
    }
}

void add(int al,int ar,int i,int x)
{
    int l=t[i].nl;
    int r=t[i].nr;
    if(al<=l&&r<=ar)t[i].chg+=x;
    else if(r<al||l>ar)return;
    else
    {
        int mid=(l+r)/2;
        add(al,ar,i*2,x);
        add(al,ar,i*2+1,x);
        t[i].v=max(t[i*2].v+t[i*2].chg,t[i*2+1].v+t[i*2+1].chg);
    }
}

int main()
{
    int N,Q;
    scanf("%d%d",&N,&Q);
    for(int i=1;i<=N;i++)scanf("%d",&a[i]);
    build(1,N,1);
    while(Q--)
    {
        int g;
        scanf("%d",&g);
        if(g==1)
        {
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            add(l,r,1,x);
        }
        else
        {
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%d\n",query(l,r,1));
        }
    }
    return 0;
}

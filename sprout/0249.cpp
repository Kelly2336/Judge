//最大連續和？
//線段樹
#include<stdio.h>
#include<iostream>
using namespace std;
int a[100005];
long long int sum[100005];

struct node
{
    int nl,nr;
    long long int rmax=0;
    long long int lmax=0;
    long long int midmax=0;
    long long int sum=0;
}tree[400100];

void build(int l,int r,int i)
{
    tree[i].nl=l;
    tree[i].nr=r;
    if(l==r)
    {
        tree[i].sum=a[l];
        if(a[l]>0)
        {
            tree[i].midmax=a[l];
            tree[i].rmax=a[l];
            tree[i].lmax=a[l];
        }
        else
        {
            tree[i].midmax=0;
            tree[i].rmax=0;
            tree[i].lmax=0;
        }
    }
    else
    {
        int mid=(l+r)/2;
        build(l,mid,i*2);
        build(mid+1,r,i*2+1);
        tree[i].sum=tree[i*2].sum+tree[i*2+1].sum;
        tree[i].midmax=max((tree[i*2].rmax+tree[i*2+1].lmax),max(tree[i*2].midmax,tree[i*2+1].midmax));
        tree[i].lmax=max(tree[i*2].lmax,tree[i*2].sum+tree[i*2+1].lmax);
        tree[i].rmax=max(tree[i*2+1].rmax,tree[i*2+1].sum+tree[i*2].rmax);
    }
}

long long int query_l(int ql,int qr,int i)
{
    int l=tree[i].nl;
    int r=tree[i].nr;
    int mid=(l+r)/2;
    if(ql==l&&qr==r)return tree[i].lmax;
    else
    {
        if(ql>mid)return query_l(ql,qr,i*2+1);
        else if(mid>=qr)return query_l(ql,qr,i*2);
        else return max(query_l(ql,mid,i*2),sum[mid]-sum[ql-1]+query_l(mid+1,qr,i*2+1));
    }
}
long long int query_r(int ql,int qr,int i)
{
    int l=tree[i].nl;
    int r=tree[i].nr;
    int mid=(l+r)/2;
    if(ql==l&&qr==r)return tree[i].rmax;
    else
    {
        if(ql>mid)return query_r(ql,qr,i*2+1);
        else if(mid>=qr)return query_r(ql,qr,i*2);
        else return max(query_r(mid+1,qr,i*2+1),sum[qr]-sum[mid]+query_r(ql,mid,i*2));
    }
}

long long int query(int ql,int qr,int i)
{
    int l=tree[i].nl;
    int r=tree[i].nr;
    int mid=(l+r)/2;
    if(l==ql&&r==qr)return tree[i].midmax;
    else
    {
        if(ql>mid)return query(ql,qr,i*2+1);
        else if(qr<=mid)return query(ql,qr,i*2);
        else return max( max(query(ql,mid,i*2),query(mid+1,qr,i*2+1)) ,query_r(ql,mid,i*2)+query_l(mid+1,qr,i*2+1));
    }
}

int main()
{
    int N,Q;
    scanf("%d%d",&N,&Q);
    sum[0]=0;
    for(int i=1;i<=N;i++)
    {
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
    }
    build(1,N,1);
    while(Q--)
    {
        int ql,qr;
        scanf("%d%d",&ql,&qr);
        printf("%lld\n",query(ql,qr,1));
    }
    /*for(int i=1;i<=N;i++)
    {
        for(int j=i;j<=N;j++)
        {
            printf("%d %d: %d %d %d\n",i,j,query(i,j,1),query_l(i,j,1),query_r(i,j,1));
        }
    }*/
    return 0;
}

//Fenwick Tree
//Binary Indexed Tree
//區間和+單點改值
#include<bits/stdc++.h>
using namespace std;
#define maxn 1000
int arr[maxn];
int bit[maxn];
int lowbit(int x)
{
    return x&(-x);
}
void init(int n)//O(N)
{
    memset(bit,0,sizeof(bit));
    for(int x=1; x<=n; x++)
    {
        bit[x]+=arr[x];
        int y=x+lowbit(x);
        if(y<=n)bit[y]+=bit[x];
    }
}
int prefix_sum(int x)//O(lgN)
{
    int sum=0;
    for(int i=x; i>0; i-=lowbit(i))
        sum+=bit[i];
    return sum;
}
int query(int a,int b)//O(lgN)
{
    return prefix_sum(b)-prefix_sum(a-1);
}
void update(int x,int n,int val)//O(lgN)
{
    for(int i=x; i<=n; i+=lowbit(i))
        bit[i]+=val;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&arr[i]);
    init(n);
    int Q;
    scanf("%d",&Q);
    while(Q--)
    {
        int r;
        scanf("%d",&r);
        if(r==1)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            printf("%d\n",query(a,b));
        }
        else
        {
            int x,add;
            scanf("%d%d",&x,&add);
            update(x,n,add);
        }
    }
    return 0;
}

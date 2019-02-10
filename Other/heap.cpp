#include<stdio.h>
using namespace std;
#define maxn 1000005
int sz;
int heap[maxn];
void SWAP(int &a,int &b){int t=a;a=b;b=t;}
void heap_init()
{
    sz=0;
}
void heap_push(int x)
{
    sz++;
    heap[sz]=x;
    int now=sz;
    while(now!=1)
    {
        int father=now>>1;
        if(heap[father]>heap[now])
        {
            SWAP(heap[father],heap[now]);
            now=father;
        }
        else break;
    }
}
void heap_pop()
{
    if(!sz)
    {
        printf("empty!\n");
        return;
    }
    printf("%d\n",heap[1]);
    heap[1]=heap[sz];
    sz--;
    int now=1;
    while(1)
    {
        int left=now<<1;
        int right=left+1;
        if(left>sz)return;//no child
        if(right>sz)//only one child
        {
            if(heap[left]<heap[now])SWAP(heap[left],heap[now]);
            return;
        }
        if(heap[right]>=heap[now]&&heap[left]>=heap[now])return;//both children bigger than father
        //choose smallest child
        if(heap[left]<heap[right])
        {
            SWAP(heap[left],heap[now]);
            now=left;
        }
        else
        {
            SWAP(heap[right],heap[now]);
            now=right;
        }
    }
}
int main()
{
    int T;
    scanf("%d",&T);
    heap_init();
    while(T--)
    {
        int k;
        scanf("%d",&k);
        if(k==1)
        {
            int n;
            scanf("%d",&n);
            heap_push(n);
        }
        else
        {
            heap_pop();
        }
    }
    return 0;
}

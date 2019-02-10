//二元搜尋樹
//input:pre_order
//output:post_order
#include<stdio.h>
using namespace std;
struct node
{
    int id;
    int father=-1;
    int right=-1;
    int left=-1;
}a[2010];
void build(int i,int r)
{
    if(a[i].id<a[r].id)
    {
        if(a[r].left==-1)
        {
            a[r].left=i;
            a[i].father=r;
        }
        else build(i,a[r].left);
    }
    else
    {
        if(a[r].right==-1)
        {
            a[r].right=i;
            a[i].father=r;
        }
        else build(i,a[r].right);
    }
}
void post_order(int i)
{
    if(a[i].left!=-1)post_order(a[i].left);
    if(a[i].right!=-1)post_order(a[i].right);
    printf("%d\n",a[i].id);
}
int main()
{
    int n=0;
    while(scanf("%d",&a[n].id)==1)
    {
        n++;
    }
    for(int i=1;i<n;i++)
    {
        build(i,0);
    }
    post_order(0);
    return 0;
}

#include<stdio.h>
using namespace std;
struct node
{
    int left=-1;
    int right=-1;
    int value=-1;
}tree[100000];

void add(int i,int p)
{
    if(tree[p].value>tree[i].value)
    {
        if(tree[p].left==-1)tree[p].left=i;
        else add(i,tree[p].left);
    }
    else
    {
        if(tree[p].right==-1)tree[p].right=i;
        else add(i,tree[p].right);
    }
}

void traversal(int i)
{
    if(tree[i].left!=-1)traversal(tree[i].left);
    if(tree[i].right!=-1)traversal(tree[i].right);
    printf("%d\n",tree[i].value);
}

int main()
{
    scanf("%d",&(tree[0].value));
    int i=1;
    while(scanf("%d",&(tree[i].value))==1)
    {
        add(i,0);
        i++;
    }
    traversal(0);
    return 0;
}

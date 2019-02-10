#include<stdio.h>
#include<string.h>
using namespace std;

char pre[30],in[30];
int n=0;

void build(int l1,int r1,int l2,int r2)
{
    if(l2>r2)return;
    if(l1>r1)return;
    char loot=pre[l1];
    int p=l2;
    while(in[p]!=loot)p++;
    int cnt=p-l2;
    build(l1+1,l1+cnt,l2,p-1);
    build(l1+cnt+1,r1,p+1,r2);
    printf("%c",loot);
    return;
}

int main()
{
    while(scanf("%s%s",pre,in)>=1)
    {
        n=strlen(pre);
        build(0,n-1,0,n-1);
        printf("\n");
    }
    return 0;
}

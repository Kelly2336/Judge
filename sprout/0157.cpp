//高棕櫚農場
//0/1背包
#include<stdio.h>
#include<iostream>
using namespace std;
#define INF 10000000
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int v[10005];
        fill(v,v+10005,INF);
        v[0]=0;
        int sum=0;
        while(n--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            sum+=b;
            for(int i=sum;i>=b;i--)
            {
                v[i]=min(v[i],v[i-b]+a);
            }
        }
        for(int i=sum;i>=0;i--)
        {
            if(v[i]<=m)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}

#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n;
        scanf("%d",&n);
        int MAX=0,x;
        while(n--)
        {
            scanf("%d",&x);
            MAX=max(MAX,x);
        }
        printf("Case %d: %d\n",i,MAX);
    }
    return 0;
}

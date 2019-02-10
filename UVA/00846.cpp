#include<stdio.h>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int x,y,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&x,&y);
        y-=x;
        printf("%d\n",max(int(ceil(sqrt(4*y)-1.0)),int(ceil(-1+sqrt(1.0+2*y)))));
    }
    return 0;
}

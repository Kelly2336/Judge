//log2 P
#include<stdio.h>
using namespace std;
int mod(int b,int p,int m)
{
    if(b==1)return 1;
    if(b==0)return 0;
    if(p==1)return b%m;
    if(p==2)return (b%m)*(b%m)%m;
    if(p%2==0)return mod(mod(b,p/2,m),2,m);
    if(p%2==1)return (b%m)*mod(mod(b,(p-1)/2,m),2,m)%m;
}
int main()
{
    int b,p,m;
    while(scanf("%d%d%d",&b,&p,&m)==3)
    {
        if(p==0)printf("1\n");
        else printf("%d\n",mod(b%m,p,m));
    }
    return 0;
}

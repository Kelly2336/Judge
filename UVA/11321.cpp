#include<bits/stdc++.h>
using namespace std;
int a[10005];
int n,m;
int cmp(int a,int b)
{
    int ma=a%m,mb=b%m;
    if(ma==mb)
    {
        int a2=a%2,b2=b%2;
        if(a2!=0)a2=1;
        if(b2!=0)b2=1;
        if(a2==b2)
        {
            if(a2)return b<a;
            return a<b;
        }
        return b2<a2;
    }
    return ma<mb;
}
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        printf("%d %d\n",n,m);
        if(!n&&!m)break;
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        sort(a,a+n,cmp);
        for(int i=0;i<n;i++)printf("%d\n",a[i]);
    }
    return 0;
}

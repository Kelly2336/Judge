#include<stdio.h>
#include<cstring>
int len[500000];
int l(int n)
{
    if(n>=100000)
    {
        if(n%2==0)return l(n/2)+1;
        else return l(3*n+1)+1;
    }
    if(len[n]!=0)return len[n];
    if(n%2==0)len[n]=l(n/2)+1;
    else len[n]=l(3*n+1)+1;
    return len[n];
}
int main()
{
    int a,b;
    memset(len,0,sizeof(len));
    len[1]=1;
    while(scanf("%d%d",&a,&b)==2)
    {
        printf("%d %d ",a,b);
        if(a>b)
        {
            int t=a;
            a=b;
            b=t;
        }
        int max=0;
        for(int i=a;i<=b;i++)
        {
            int ans=l(i);
            if(ans>max)
            {
                max=ans;
            }
        }
        printf("%d\n",max);
    }
    return 0;
}

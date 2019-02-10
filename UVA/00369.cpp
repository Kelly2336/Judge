#include<stdio.h>
int main()
{
    while(1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if(n==0&&m==0)break;
        printf("%d things taken %d at a time is",n,m);
        if(m>n-m)m=n-m;
        long long int ans=1;
        for(int i=1;i<=m;i++)
        {
            if(n>70)ans=ans/i*(n-i+1);
            else ans=ans*(n-i+1)/i;
        }
        printf(" %llu exactly.\n",ans);
    }
    return 0;
}

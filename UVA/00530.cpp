#include<stdio.h>
int main()
{
    while(1)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        if(n==0&&m==0)break;
        if(m>n-m)m=n-m;
        long long int ans=1;
        for(int i=1;i<=m;i++)
        {
            ans=ans*(n-i+1)/i;
        }
        printf("%d\n",ans);
    }
    return 0;
}

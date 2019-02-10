#include<stdio.h>
#include<cstring>
int main()
{
    int n,r;
    while(scanf("%d%d",&n,&r)>=1)
    {
        bool a[10010];
        memset(a,0,sizeof(a));
        for(int i=0;i<r;i++)
        {
            int x;
            scanf("%d",&x);
            a[x]=true;
        }
        if(n==r)printf("*\n");
        else
        {
            for(int i=1;i<=n;i++)
            {
                if(!a[i])printf("%d ",i);
            }
            printf("\n");
        }
    }
    return 0;
}

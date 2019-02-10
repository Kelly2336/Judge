#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int n,k;
    while(scanf("%d%d",&n,&k)==2)
    {
        if(!n&&!k)break;
        for(int i=1;i<=n;i++)
        {
            int a[120];
            bool success=true;
            for(int e=1;e<=n;e++)
            {
                a[e]=e;
            }
            int p=i-1;
            if(p<1)p+=n;
            for(int t=1;t<=n-1;t++)
            {
                for(int j=0;j<k;j++)
                {
                    p++;if(p>n)p-=n;
                    while(!a[p])
                    {
                        p++;if(p>n)p-=n;
                    }
                }
                int pp=p;
                //printf("%d ",a[p]);
                if(a[p]==1)
                {
                    success=false;
                    break;
                }
                a[p]=0;
                for(int j=0;j<k;j++)
                {
                    p++;if(p>n)p-=n;
                    while(!a[p])
                    {
                        p++;if(p>n)p-=n;
                    }
                }
                a[pp]=a[p];
                a[p]=0;
                p=pp;
            }
            if(success)
            {
                printf("%d\n",i);
                break;
            }
        }
    }
    return 0;
}

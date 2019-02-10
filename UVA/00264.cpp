#include<stdio.h>
int main()
{
    int a[5000];
    a[0]=0;
    for(int i=1;i<5000;i++)
    {
        a[i]=a[i-1]+i;
    }

    int n;
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<5000;i++)
        {
            if(a[i]>=n)
            {
                int d=n-a[i-1];
                int m=i+1-d;
                if(i%2==1)
                {
                    int t=d;
                    d=m;
                    m=t;
                }
                printf("TERM %d IS %d/%d\n",n,d,m);
                break;
            }
        }
    }
    return 0;
}

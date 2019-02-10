#include<stdio.h>
#include<algorithm>
int main()
{
    while(1)
    {
        int n;
        if(scanf("%d",&n)<1)break;
        int a[3000];
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        int d[3000];
        for(int i=0;i<n-1;i++)
        {
            d[i]=a[i+1]-a[i];
            if(d[i]<0)d[i]*=-1;
        }
        std::sort(d,d+n-1);
        bool jolly=true;
        for(int i=0;i<n-2;i++)
        {
            if(d[i]!=d[i+1]-1)
            {
                jolly=false;
                break;
            }
        }
        if(n==1||jolly&&d[0]==1)printf("Jolly\n");
        else printf("Not jolly\n");
    }
    return 0;
}

//角落的書櫃
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    long long int a[100005];
    for(int i=0; i<n-1; i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a,a+n-1);

    if(n==2)
    {
        if(a[0]==1)printf("2\n");
        else printf("1\n");
        return 0;
    }

    if(n==3)
    {
        if((2*a[0]-a[1])>0)
        {
            printf("%lld\n",2*a[0]-a[1]);//2 3
            return 0;
        }
        if((a[1]-a[0])%2==0)
        {
            printf("%lld\n",(a[0]+a[1])/2);//1 3
            return 0;
        }
        printf("%lld\n",a[1]*2-a[0]);//1 2
        return 0;
    }

    long long int d=a[1]-a[0];
    for(int i=1; i<n-1; i++)
    {
        long long int dd=a[i]-a[i-1];
        if(dd<d)
        {
            printf("%lld\n",(a[0]+a[1])/2);
            return 0;
        }
        else if(dd>d)
        {
            printf("%lld\n",(a[i-1]+a[i])/2);
            return 0;
        }
    }


    if((a[0]-d)>0)
    {
        printf("%lld\n",a[0]-d);
    }
    else
    {
        printf("%lld\n",a[n-2]+d);
    }
    return 0;
}

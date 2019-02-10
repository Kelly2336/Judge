#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int a[10000];
    for(int i=0;i<10000;i++)
    {
        int t;
        if(scanf("%d",&t)<1)break;
        //sort(a,a+1+i);
        int k=i;
        for(int j=0;j<i;j++)
        {
            if(a[j]>t)
            {
                k=j;
                break;
            }
        }
        for(int j=i-1;j>=k;j--)
        {
            a[j+1]=a[j];
        }
        a[k]=t;
        if(i%2==0)printf("%d\n",a[i/2]);
        else printf("%d\n",(a[i/2]+a[i/2+1])/2);
    }
    return 0;
}

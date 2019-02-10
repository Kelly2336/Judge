//田忌賽馬
//二分搜
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        long long int a[10005];
        int b[10005];
        long long int c[10005];
        for(int i=0;i<n;i++)
            scanf("%lld%d",&a[i],&b[i]);
        for(int i=0;i<n;i++)
            scanf("%lld",&c[i]);
        sort(c,c+n);
        long long int m=-1;
        long long int small=0;
        long long int big=100000100;
        while(small<=big)
        {
            long long int mid=(small+big)/2;
            unsigned long long int d[10005];
            for(int i=0;i<n;i++)
                d[i]=a[i]+mid*b[i];
            sort(d,d+n);
            int win=0;
            for(int di=0,ci=0;di<n&&ci<n&&win<k;di++)
            {
                if(d[di]>c[ci])
                {
                    ci++;
                    win++;
                }
            }
            if(win==k)
            {
                if(m==-1||m>mid)m=mid;
                big=mid-1;
            }
            else
            {
                small=mid+1;
            }
        }
        printf("%d\n",m);
    }
    return 0;
}

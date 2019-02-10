#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        int n;
        scanf("%d",&n);
        int a[50];
        int high=0,low=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if(i-1>=0)
            {
                if(a[i]>a[i-1])high++;
                else if(a[i]<a[i-1])low++;
            }
        }
        printf("Case %d: %d %d\n",i,high,low);
    }
    return 0;
}

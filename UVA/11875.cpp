#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        int n;
        scanf("%d",&n);
        int a[15];
        for(int j=0;j<n;j++)scanf("%d",&a[j]);
        printf("Case %d: %d\n",i,a[n/2]);
    }
    return 0;
}

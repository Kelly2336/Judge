#include<stdio.h>
#include<cmath>
int main()
{
    printf("PERFECTION OUTPUT\n");
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        int s=sqrt(n);
        int sum=1;
        for(int i=2;i<=s;i++)
        {
            if(n%i==0)sum+=i+(n/i);
        }
        printf("%5d",n);
        if(sum<n||n==1)printf("  DEFICIENT\n");
        else if(sum==n)printf("  PERFECT\n");
        else printf("  ABUNDANT\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}

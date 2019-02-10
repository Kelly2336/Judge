#include<stdio.h>
#include<cmath>
int gcd(int a,int b)
{
    if(a%b==0)return b;
    return gcd(b,a%b);
}
int main()
{
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        int a[60];
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        int r=0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(gcd(a[i],a[j])==1)r++;
            }
        }
        if(!r)printf("No estimate for this data set.\n");
        else
        {
            printf("%.6f\n",sqrt(3.0*(n)*(n-1)/r));
        }
    }
    return 0;
}

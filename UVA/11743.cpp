#include<stdio.h>
int even(int d)
{
    int ans=0;
    d*=2;
    while(d>0)
    {
        ans+=d%10;
        d/=10;
    }
    return ans;
}
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int sum=0;
        for(int i=0;i<4;i++)
        {
            int a;
            scanf("%d",&a);
            sum+=even(a/1000);
            sum+=(a/100%10);
            sum+=even(a%100/10);
            sum+=(a%10);
        }
        if(sum%10==0)printf("Valid\n");
        else printf("Invalid\n");
    }
    return 0;
}

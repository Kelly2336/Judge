#include<stdio.h>
int main()
{
    int n;
    while(scanf("%d",&n)>=1&&n!=0)
    {
        while(n>=10)
        {
            int t=0;
            while(n>0)
            {
                t+=(n%10);
                n/=10;
            }
            n=t;
        }
        printf("%d\n",n);
    }
    return 0;
}

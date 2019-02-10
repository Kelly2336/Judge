#include<stdio.h>
#include<cmath>
int main()
{
    int n;
    scanf("%d",&n);
    for(;n>0;n--)
    {
        int a;
        scanf("%d",&a);
        int len=log10(a)+1;
        bool find=false;
        for(int i=a-len*10;i<=a;i++)
        {
            if(i<=1)i=1;
            int t=i;
            int sum=i;
            while(t>0)
            {
                sum+=t%10;
                t/=10;
            }
            if(sum==a)
            {
                printf("%d\n",i);
                find=true;
                break;
            }
        }
        if(!find)printf("0\n");
    }
    return 0;
}

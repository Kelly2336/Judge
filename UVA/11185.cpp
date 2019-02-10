#include<stdio.h>
int main()
{
    while(1)
    {
        int k;
        scanf("%d",&k);
        if(k<0)break;
        if(k==0)
        {
            printf("0\n");
        }
        else
        {
            int t=0;
            int a[100];
            while(k!=0)
            {
                a[t]=k%3;
                k/=3;
                t++;
            }
            for(int i=t-1;i>=0;i--)
            {
                printf("%d",a[i]);
            }
            printf("\n");
        }
    }
    return 0;
}

#include<stdio.h>
#include<string.h>
int main()
{
    int n,kase=0;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        if(kase>0)printf("\n");
        kase++;
        int output=0;
        for(int b=1234;b<=49876;b++)
        {
            int a=b*n;
            int t[10];
            memset(t,0,sizeof(t));
            int i=a,j=b;
            if(i<10000)t[0]++;
            if(j<10000)t[0]++;
            while(i>0)
            {
                t[i%10]++;
                i/=10;
            }
            while(j>0)
            {
                t[j%10]++;
                j/=10;
            }
            bool div=true;
            for(int k=0;k<=9;k++)
            {
                if(t[k]!=1)div=false;
            }
            if(div)
            {
                printf("%05d / %05d = %d\n",a,b,n);
                output++;
            }
        }
        if(!output)printf("There are no solutions for %d.\n",n);
    }
    return 0;
}

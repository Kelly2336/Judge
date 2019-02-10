#include<stdio.h>
int main()
{
    int N,C;
    while(scanf("%d%d",&N,&C)>=1)
    {
        printf("%d %d:",N,C);
        int prime[1000];
        int p=1;
        prime[0]=1;
        if(N>=2)
        {
            p++;
            prime[1]=2;
        }
        for(int i=3;i<=N;i++)
        {
            bool isprime=true;
            for(int j=1;j<p;j++)
            {
                if(i%prime[j]==0)
                {
                    isprime=false;
                    break;
                }
            }
            if(isprime)
            {
                prime[p]=i;
                p++;
            }
        }
        if(p%2==1)
        {
            C=C*2-1;
        }
        else
        {
            C*=2;
        }
        if(C<=p)
        {
            for(int i=(p-C)/2;i<(p-C)/2+C;i++)
            {
                printf(" %d",prime[i]);
            }
        }
        else
        for(int i=0;i<p;i++)
        {
            printf(" %d",prime[i]);
        }
        printf("\n\n");
    }
    return 0;
}

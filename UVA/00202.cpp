#include<stdio.h>
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int a,b;
    while(scanf("%d %d",&a,&b)==2)
    {
        printf("%d/%d = %d.",a,b,a/b);
        int cycle=0,len=0;
        int q[4000],r[4000];
        r[0]=a%b;
        for(int i=1;i<=b+5;i++)
        {
            a=r[i-1]*10;
            q[i]=a/b;
            r[i]=a%b;
            //printf("%d %d\n",q[i],r[i]);
            for(int j=0;j<i;j++)
            {
                if(r[i]==r[j])
                {
                    len=i;
                    cycle=i-j;
                    break;
                }
            }
            if(len!=0)break;
        }
        for(int i=1;i<=len-cycle;i++)
        {
            printf("%d",q[i]);
        }
        printf("(");
        if(cycle<=50)
        {
            for(int i=len-cycle+1;i<=len;i++)
            {
                printf("%d",q[i]);
            }
        }
        else
        {
            for(int i=len-cycle+1;i<=len-cycle+50;i++)
            {
                printf("%d",q[i]);
            }
            printf("...");
        }
        printf(")\n");
        //printf("%d %d\n",len,cycle);
        printf("   %d = number of digits in repeating cycle\n\n",cycle);
    }
    return 0;
}

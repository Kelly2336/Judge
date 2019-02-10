#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    for(;t>0;t--)
    {
        int L,n;
        scanf("%d%d",&L,&n);
        int max=0,min=0;
        for(int i=0;i<n;i++)
        {
            int d;
            scanf("%d",&d);
            int d2=L-d;
            if(d>d2)
            {
                int t=d;
                d=d2;
                d2=t;
            }//d<d2
            if(d>min)min=d;
            if(d2>max)max=d2;
        }
        printf("%d %d\n",min,max);
    }
    return 0;
}

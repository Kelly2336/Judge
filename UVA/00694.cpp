#include<stdio.h>
int main()
{
    int c=0;
    while(1)
    {
        int a,limit,num=1;
        scanf("%d%d",&a,&limit);
        if(a<0&&limit<0)break;
        long int A=a;
        c++;
        while(1)
        {
            if(A==1||A>limit)
            {
                if(A>limit)num--;
                printf("Case %d: A = %d, limit = %d, number of terms = %d\n",c,a,limit,num);
                break;
            }
            if(A%2==0)
            {
                A/=2;
                num++;
            }
            else
            {
                A=3*A+1;
                num++;
            }
        }
    }
    return 0;
}

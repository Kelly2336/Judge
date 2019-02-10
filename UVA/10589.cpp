#include<stdio.h>
int main()
{
    int n,a;
    while(scanf("%d%d",&n,&a)>=2&&n!=0)
    {
        double x,y;
        int m=0;
        int d=a*a;
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&x,&y);
            if(x*x+y*y<=d && (a-x)*(a-x)+(a-y)*(a-y)<=d && x*x+(a-y)*(a-y)<=d && (a-x)*(a-x)+y*y<=d)
                m++;
        }
        printf("%.5f\n",m*1.0*a/n*a);
    }
    return 0;
}

#include<stdio.h>
using namespace std;
int main()
{
    double N,U,D,F;
    while(1)
    {
        scanf("%lf%lf%lf%lf",&N,&U,&D,&F);
        if(N==0)break;
        double H=N;
        int day=1;
        double m=U*F/100.0;
        while(H>0)
        {
            H-=U;
            U-=m;
            if(U<0)U=0;
            if(H<0)
            {
                printf("success on day %d\n",day);
                break;
            }
            H+=D;
            if(H>N)
            {
                printf("failure on day %d\n",day);
                break;
            }
            day++;
        }
    }
    return 0;
}

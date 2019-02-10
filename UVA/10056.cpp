#include<stdio.h>
#include<cmath>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int N,P;
        double r;
        scanf("%d%lf%d",&N,&r,&P);
        double ans=0;
        double Rn=pow(1-r,N);
        int i=0;
        while(1)
        {
            double ai=pow(Rn,i)*pow(1-r,P-1)*r;
            ans+=ai;
            if(ai<1e-6)break;
            i++;
        }
        printf("%.4lf\n",ans);
    }
    return 0;
}

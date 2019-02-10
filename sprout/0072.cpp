//Happiness Function
//三分搜
#include<stdio.h>
#include<iostream>
using namespace std;
double A[20],B[20],C[20];
int n;

double small(double t)
{
    double s=A[0]*(B[0]-t)*(B[0]-t)+C[0];
    for(int i=1;i<n;i++)
    {
        double z=A[i]*(B[i]-t)*(B[i]-t)+C[i];
        if(z>s)s=z;
    }
    return s;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%lf%lf%lf",&A[i],&B[i],&C[i]);
        double s=0;
        double b=300;
        double ans;
        while(b-s>1e-9)
        {
            double l=(s*2+b)/3.0;
            double r=(s+b*2)/3.0;
            double sl=small(l);
            double sr=small(r);
            if(sl<sr)b=r;
            else s=l;
            //printf("%.5lf %.5lf\n",s,b);
        }
        ans=min(small(s),small(b));
        printf("%.5lf\n",ans);
    }
    return 0;
}

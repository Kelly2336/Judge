//牛頓勘根
//Time:1.820 Rank:5994
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int p,q,r,s,t,u;
    while(scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u)==6)
    {
        double ans=-1;
        double last=p*exp(0)+q*sin(0)+r*cos(0)+s*tan(0)+u;
        if(last==0)ans=0;
        else
        {
            for(double x=0.00005; x<=1.000051; x+=0.00005)
            {
                double now=p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
                if(now==0)
                {
                    ans=x;
                    break;
                }
                if(now*last<=0)
                {
                    ans=x-0.00005;
                    break;
                }
                last=now;
                //printf("%.5lf %.5lf\n",x,last);
            }
        }
        if(ans<-0.1)printf("No solution\n");
        else printf("%.4lf\n",ans+1e-6);
    }
    return 0;
}
//http://www.algorithmist.com/index.php/UVa_10341
//Bisection method
//二分搜 (binary search)
//Time:0.000 Rank:468
//因為f(x)有單調遞減性質
#include<bits/stdc++.h>
using namespace std;
const double EPS=1e-7;
int p,q,r,s,t,u;
inline double f(double x)
{
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}
int main()
{
    while(scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u)==6)
    {
        if(f(0)*f(1)>0)
        {
            printf("No solution\n");
            continue;
        }
        double low=0,high=1;
        double mid;
        while(low+EPS<high)
        {
            mid=(low+high)/2;
            if(f(low)*f(mid)<=0)high=mid;
            else low=mid;
        }
        printf("%.4lf\n",(low+high)/2);
    }
    return 0;
}

//Secant method

//Newton's method

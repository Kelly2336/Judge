#include<stdio.h>
#include<cmath>
using namespace std;
int main()
{
    for(long long int k=6,cnt=0;cnt<10;k++)
    {
        //n=(-1+sqrt(1+4k+4k*k))/2
        long long int h=8*k*k+1;
        long long int s=sqrt(h);
        if(s*s==h)
        {
            printf("%10lld%10lld\n",k,(s-1)/2);
            cnt++;
        }
    }
    return 0;
}

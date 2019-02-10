#include<stdio.h>
using namespace std;
#define maxn 51
int main()
{
    long long int male[maxn],sum[maxn];
    male[0]=0;
    sum[0]=1;
    for(int i=1;i<maxn;i++)
    {
        male[i]=sum[i-1];
        sum[i]=male[i]+male[i-1]+1;
    }
    /*unsigned long long int male[maxn],female[maxn],sum[maxn];
    male[0]=0;
    female[0]=1;
    sum[0]=1;
    for(int i=1;i<maxn;i++)
    {
        male[i]=female[i-1]+male[i-1];
        female[i]=male[i-1]+1;
        sum[i]=male[i]+female[i];
    }*/
    int n;
    while(scanf("%d",&n)==1&&n!=-1)
    {
        printf("%lld %lld\n",male[n],sum[n]);
    }
    return 0;
}

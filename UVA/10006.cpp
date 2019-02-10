#include<stdio.h>
#include<string.h>
using namespace std;
bool isprime[66000];
void build()
{
    memset(isprime,0,sizeof(isprime));
    isprime[0]=1;
    isprime[1]=1;
    for(int i=4;i<66000;i+=2)
    {
        isprime[i]=true;
    }
    for(int i=3;i<300;i+=2)
    {
        if(isprime[i])continue;
        for(int j=i*i;j<66000;j+=i*2)
        {
            isprime[j]=true;
        }
    }
}

int main()
{
    build();
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        bool success=true;
        if(!isprime[n])success=false;
        for(int i=2;i<n&&success;i++)
        {
            long long x=i;
            long long res=1;
            int m=n;
            while(m>0)
            {
                if(m&1)
                {
                    res=res*x%n;
                }
                x=x*x%n;
                m=m>>1;
            }
            if(res!=i)success=false;
        }
        if(success)printf("The number %d is a Carmichael number.\n",n);
        else printf("%d is normal.\n",n);
    }
    return 0;
}

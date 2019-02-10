#include<bits/stdc++.h>
using namespace std;
int prime[200]={2};
int p=1;
void table()
{
    for(int i=3;i<1000;i+=2)
    {
        bool isprime=true;
        for(int j=1;j<p;j++)
        {
            if(i%prime[j]==0)
            {
                isprime=false;
                break;
            }
        }
        if(isprime)prime[p++]=i;
    }
}
bool isprime(int n)
{
    int sq=sqrt(n);
    for(int i=0;i<p&&prime[i]<=sq;i++)
    {
        if(n%prime[i]==0)return false;
    }
    return true;
}
int main()
{
    table();
    int n;
    while(scanf("%d",&n)==1)
    {
        if(isprime(n))
        {
            int k=n;
            int n2=0;
            while(k)
            {
                n2=n2*10+k%10;
                k/=10;
            }
            if(n!=n2&&isprime(n2))printf("%d is emirp.\n",n);
            else printf("%d is prime.\n",n);
        }
        else printf("%d is not prime.\n",n);
    }
    return 0;
}

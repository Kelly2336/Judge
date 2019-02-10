#include<bits/stdc++.h>
using namespace std;
int twin[100005];
int prime[1000];
int ti=0,pi=0;
bool isprime(int x)
{
    int sq=sqrt(x);
    for(int i=0;i<pi&&prime[i]<=sq;i++)
    {
        if(x%prime[i]==0)return false;
    }
    return true;
}
int main()
{
    prime[pi++]=2;
    bool last=false;
    for(int i=3;i<5000;i+=2)
    {
        if(isprime(i))
        {
            prime[pi++]=i;
            if(last)twin[ti++]=i;
            last=true;
        }
        else last=false;
    }
    for(int i=5001;ti<100000;i+=2)
    {
        if(isprime(i))
        {
            if(last)twin[ti++]=i;
            last=true;
        }
        else last=false;
        if(!last&&i%3==2)i+=4;
    }
    int n;
    while(scanf("%d",&n)==1)
    {
        n--;
        printf("(%d, %d)\n",twin[n]-2,twin[n]);
    }
    return 0;
}

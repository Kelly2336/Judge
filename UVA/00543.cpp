#include<stdio.h>
bool isprime[1000000];
int prime[100000];
int p=1;
void find_prime()
{
    isprime[0]=false;
    isprime[1]=false;
    isprime[2]=true;
    prime[0]=2;
    for(int i=3;i<1000000;i+=2)isprime[i]=true;
    for(int i=4;i<1000000;i+=2)isprime[i]=false;
    for(int i=3;i<1000000;i+=2)
    {
        if(isprime[i])
        {
            prime[p]=i; p++;
            for(int j=i*3;j<1000000;j+=2*i)isprime[j]=false;
        }
    }
}
int main()
{
    find_prime();

    while(1)
    {
        int n;
        scanf("%d",&n);
        if(n==0)break;
        bool found=false;
        for(int i=1;i<p&&prime[i]<=n/2;i++)
        {
            if(isprime[n-prime[i]])
            {
                printf("%d = %d + %d\n",n,prime[i],n-prime[i]);
                found=true;
                break;
            }
        }
        if(!found)printf("Goldbach's conjecture is wrong.\n");
    }
    return 0;
}

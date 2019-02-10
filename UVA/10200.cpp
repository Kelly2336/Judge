#include<stdio.h>
#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

#define maxn 11000
bool prime[maxn];
int prime_table[2000];
int p=0;
void get_prime()
{
    memset(prime,0,sizeof(prime));
    prime[0]=true;
    prime[1]=true;
    for(int i=2;i<maxn;i++)
    {
        if(!prime[i])
        {
            prime_table[p]=i;
            p++;
            for(int j=i*i;j<maxn;j+=i)
            {
                prime[j]=true;
            }
        }
    }
    //printf("%d",p);
}
int isprime(int n)
{
    int s=sqrt(n);
    for(int i=0;prime_table[i]<=s;i++)
    {
        if(n%prime_table[i]==0)return -1;
    }
    return 1;
}
int Euler(int n)
{
    return n*(n+1)+41;
}
int main()
{
    int a,b;
    get_prime();
    int n[10005];
    memset(n,0,sizeof(n));
    while(scanf("%d%d",&a,&b)==2)
    {
        int ans=0;
        for(int i=a;i<=b;i++)
        {
            if(n[i]==0)
            {
                n[i]=isprime(Euler(i));
            }
            if(n[i]==1)ans++;
        }
        printf("%.2lf",ans*100.0/(b-a+1)+1e-9);
        cout<<endl;
    }
    return 0;
}

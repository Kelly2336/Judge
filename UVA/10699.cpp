#include<stdio.h>
#include<cmath>
#include<iostream>
#include<string.h>
using namespace std;

#define maxn 1005
bool prime[maxn];
int prime_table[1000];
int p=0;
void get_prime()
{
    memset(prime,0,sizeof(prime));
    prime[0]=true;
    prime[1]=true;
    for(int i=2; i<maxn; i++)
    {
        if(!prime[i])
        {
            prime_table[p]=i;
            p++;
            for(int j=i*i; j<maxn; j+=i)
            {
                prime[j]=true;
            }
        }
    }
    //printf("%d",p);
    /*for(int i=0;i<p;i++)
    {
        printf("%d",prime_table[i]);
        cout<<endl;
    }*/
}

int main()
{
    get_prime();
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)break;
        int s=n;
        int ans=0;
        for(int i=0; prime_table[i]<=sqrt(s); i++)
        {
            if(s%prime_table[i]==0)ans++;
            while(s%prime_table[i]==0)s/=prime_table[i];
        }
        if(s>1)ans++;
        printf("%d : %d",n,ans);
        cout<<endl;
    }
    return 0;
}

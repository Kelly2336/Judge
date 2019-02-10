#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
int first[1000005];
int num[1000005];
int ans[1000005];
int p[1000005];

int gcd(int a,int b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}

bool coprime(int x,int y,int z)
{
    if(gcd(gcd(x,y),z)==1)return true;
    return false;
}

int main()
{
    fill(first,first+1000002,1000001);
    memset(p,0,sizeof(p));
    for(int m=2;m<1000;m++)
    {
        for(int n=%2+1;n<m;n+=2)
        {
            if(gcd(m,n)!=1)continue;
            int x=m*m-n*n;
            int y=2*m*n;
            int z=m*m+n*n;
            if(z>1000000)break;
            if(coprime(x,y,z))
            {
                p[z]++;
                for(int k=1000000/z;k>=1;k--)
                {
                    int xx=x*k;
                    int yy=y*k;
                    int zz=z*k;
                    first[xx]=min(first[xx],zz);
                    first[yy]=min(first[yy],zz);
                    first[zz]=zz;
                }
            }
        }
    }
    memset(num,0,sizeof(num));
    for(int i=1;i<=1000000;i++)
    {
        p[i]+=p[i-1];
        num[first[i]]++;
    }
    ans[1]=1;
    for(int i=2;i<=1000000;i++)
    {
        ans[i]=ans[i-1]+1-num[i];
    }
    int N;
    while(scanf("%d",&N)==1)
    {
        printf("%d %d\n",p[N],ans[N]);
    }
    return 0;
}

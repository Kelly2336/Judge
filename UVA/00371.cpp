#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    long long int a,b;
    int n[10000]={0};
    memset(n,0,10000);
    n[1]=3;
    n[2]=1;
    for(int i=3;i<10000;i++)
    {
        int r=i;
        while(r>10000||n[r]==0)
        {
            if(r%2==0)
            {
                r/=2;
            }
            else
            {
                r=3*r+1;
            }
            if(r<10000&&n[r]!=0)
            {
                n[i]+=n[r];
                break;
            }
            else n[i]++;
        }
        n[i]++;
        //printf("%d %d\n",i,n[i]);
    }
    while(1)
    {
        scanf("%d%d",&a,&b);
        if(a==0&&b==0)break;
        if(a>b)swap(a,b);
        int maxlen=0;
        long long int maxi=a;
        for(long long int i=a;i<=b;i++)
        {
            long long int len=0;
            long long int r=i;
            while(r>=10000)
            {
                if(r%2==0)
                {
                    r/=2;
                }
                else r=3*r+1;
                len++;
            }
            len+=n[r];
            if(len>maxlen)
            {
                maxlen=len;
                maxi=i;
            }
        }
        printf("Between %lld and %lld, %lld generates the longest sequence of %d values.\n",a,b,maxi,maxlen);
    }
    return 0;
}

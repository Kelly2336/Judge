//円円數磁磚
//DP
#include<stdio.h>
#include<string.h>
using namespace std;
int mod=1000007;
unsigned int f[100005];
void solve()
{
    memset(f,0,sizeof(f));
    f[0]=1;
    f[1]=0;
    f[2]=3;
    f[4]=f[2]*f[2]+2;
    int sum=f[2];
    for(int i=4;i<=100000;i+=2)
    {
        f[i]=(sum*2+2+f[i-2])%mod;
        sum+=f[i];
        sum%=mod;
    }
}
int main()
{
    solve();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",f[n]);
    }
    return 0;
}

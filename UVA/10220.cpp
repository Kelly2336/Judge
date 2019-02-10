#include<stdio.h>
#include<string.h>
using namespace std;
int a[1005][3005];
int sum[1005];
int main()
{
    memset(a,0,sizeof(a));
    memset(sum,0,sizeof(sum));
    a[1][0]=1;sum[1]=1;
    for(int i=2;i<=1000;i++)
    {
        for(int j=0;j<3000;j++)
        {
            a[i][j]+=a[i-1][j]*i;
            a[i][j+1]+=a[i][j]/10;
            a[i][j]%=10;
            sum[i]+=a[i][j];
        }
    }
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("%d\n",sum[n]);
    }
    return 0;
}

#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    int a[1005][305];
    memset(a,0,sizeof(a));
    a[0][0]=1;a[1][0]=2;
    for(int i=2;i<=1000;i++)
    {
        for(int j=0;j<300;j++)
        {
            a[i][j]+=a[i-1][j]+a[i-2][j];
            a[i][j+1]+=(a[i][j]/10);
            a[i][j]%=10;
        }
    }
    int n;
    while(scanf("%d",&n)==1)
    {
        bool zero=false;
        for(int i=300;i>=0;i--)
        {
            if(a[n][i])zero=true;
            if(zero)printf("%d",a[n][i]);
        }
        printf("\n");
    }
    return 0;
}

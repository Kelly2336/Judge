#include<stdio.h>
#include<string.h>
using namespace std;
short int a[1005][3001];
int main()
{
    memset(a,0,sizeof(a));
    a[0][0]=1;
    for(int i=1;i<=1000;i++)
    {
        for(int j=0;j<=i*4&&j<3000;j++)
        {
            a[i][j]+=a[i-1][j]*i;
            a[i][j+1]+=a[i][j]/10;
            a[i][j]%=10;
        }
    }
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("%d!\n",n);
        bool zero=false;
        for(int i=3000;i>=0;i--)
        {
            if(a[n][i])zero=true;
            if(zero)printf("%d",a[n][i]);
        }
        printf("\n");
    }
    return 0;
}

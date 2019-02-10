#include<stdio.h>
#include<cstring>
#define maxn 5010
#define len 1200
int a[maxn][len];
int main()
{
    int n;
    memset(a,0,sizeof(a));
    a[1][0]=1;
    for(int i=2;i<maxn;i++)
    {
        for(int j=0;j<len-1;j++)
        {
            a[i][j]+=a[i-1][j]+a[i-2][j];
            if(a[i][j]>=10)
            {
                a[i][j+1]+=a[i][j]/10;
                a[i][j]%=10;
            }
        }
    }
    while(scanf("%d",&n)==1)
    {
        printf("The Fibonacci number for %d is ",n);
        int i=len-1;
        for(;i>=1;i--)
        {
            if(a[n][i]!=0)break;
        }
        for(;i>=0;i--)
        {
            printf("%d",a[n][i]);
        }
        printf("\n");
    }
    return 0;
}

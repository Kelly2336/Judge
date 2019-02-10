//玩電梯
//DP
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
const int MOD=1e9+7;
long long int m[2][2010];
long long int sum[2][2010];
int main()
{
    int n,a,b,k;
    scanf("%d%d%d%d",&n,&a,&b,&k);
    memset(m,0,sizeof(m));
    memset(sum,0,sizeof(sum));
    m[0][a]=1;
    for(int i=a;i<=n;i++)sum[0][i]=1;

    for(int i=1;i<=k;i++)
    {
        for(int y=1;y<=n;y++)
        {
            if(y<b)
            {
                m[i%2][y]=(sum[(i-1)%2][(y+b+1)/2-1]-m[(i-1)%2][y]+MOD)%MOD;
            }
            else if(y>b)
            {
                m[i%2][y]=(sum[(i-1)%2][n]-sum[(i-1)%2][(b+y)/2]-m[(i-1)%2][y]+MOD*2)%MOD;
            }
            sum[i%2][y]=(sum[i%2][y-1]+m[i%2][y])%MOD;
        }
    }
    printf("%d\n",sum[k%2][n]);
    return 0;
}

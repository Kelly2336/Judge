#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int m;
        scanf("%d",&m);
        int c[105];
        int sum=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d",&c[i]);
            sum+=c[i];
        }
        bool dp[30000];
        memset(dp,0,sizeof(dp));
        dp[0]=true;
        for(int i=0;i<m;i++)
        {
            for(int j=sum/2;j>=c[i];j--)
            {
                if(dp[j-c[i]])dp[j]=true;
            }
        }
        for(int j=sum/2;j>=0;j--)
        {
            if(dp[j])
            {
                printf("%d\n",sum-j*2);
                break;
            }
        }
    }
    return 0;
}

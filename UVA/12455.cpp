#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int p;
        scanf("%d",&p);
        int a[25];
        for(int i=0;i<p;i++)
        {
            scanf("%d",&a[i]);
        }
        int dp[1200];
        memset(dp,0,sizeof(dp));
        dp[0]=true;
        for(int i=0;i<p;i++)
        {
            for(int j=n;j>=a[i];j--)
            {
                if(dp[j-a[i]])
                {
                    dp[j]=true;
                }
            }
        }
        if(dp[n])printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
#define maxn 1005
long long int dp[maxn][maxn];
int main()
{
	while(1)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		if(!n&&!m)break;
		long long int a[maxn];
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		memset(dp,0,sizeof(dp));
		long long int ans=0;
		dp[1][1]=a[1]%m;
		for(int i=2;i<=n;i++)
		{
			dp[i][1]=(dp[i-1][1]+a[i])%m;
			for(int j=2;j<=i;j++)
			{
				dp[i][j]=(dp[i-1][j-1]*a[i]%m+dp[i-1][j])%m;
			}
		}
		for(int j=1;j<=n;j++)
			ans=max(ans,dp[n][j]);
		printf("%lld\n",ans);
	}
	return 0;
}

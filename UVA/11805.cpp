#include<stdio.h>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	for(int ti=1;ti<=T;ti++)
	{
		int N,K,P;
		scanf("%d%d%d",&N,&K,&P);
		int ans=(K+P)%N;
		if(!ans)ans=N;
		printf("Case %d: %d\n",ti,ans);
	}
	return 0;
}

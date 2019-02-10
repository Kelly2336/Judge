#include<stdio.h>
int main()
{
	long long int n;
	while(scanf("%lld",&n)==1)
	{
		n = n*(n+1)/2;
		printf("%lld\n",n*n);
	}
	return 0;
}

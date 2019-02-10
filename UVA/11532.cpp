#include<stdio.h>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int P,Q;
		scanf("%d%d",&P,&Q);
		unsigned long long int ans = 0;
		if(P)
		{
			if(P==1)ans = 1;
			else if(P==2*Q)
			{
				while(Q--)
					ans = (ans<<3)|5;
			}
			else if(P>2*Q)
			{
				while((Q--)&&(P=P-2))
					ans = (ans<<3)|5;
				while(P--)
					ans = (ans<<1)|1;
			}
			else//P<2Q
			{
				if(P%2)ans=1,P--;
				for(;P;P-=2)
				{
					ans = (ans<<3)|5;
				}
			}
		}
		printf("%llu\n",ans);
	}
	return 0;
}

#include<stdio.h>
using namespace std;
#define maxn 55
int main()
{
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(!n)break;
		int x[maxn],y[maxn];
		for(int i=0;i<n;i++)
		{
			scanf("%d%d",&x[i],&y[i]);
		}
		bool convex_hall = true;
		int a1 = 0;
		for(int i=0;i<n;i++)
		{
			int j = (i+1)%n;
			int k = (i+2)%n;
			int x1 = x[j]-x[i];
			int y1 = y[j]-y[i];
			int x2 = x[k]-x[j];
			int y2 = y[k]-y[j];
			int a2 = x1*y2-x2*y1;
			if(a1*a2<0)
			{
				convex_hall = false;
				break;
			}
			a1 = a2;
		}
		if(convex_hall)printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}

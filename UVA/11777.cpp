#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	for(int ti=1;ti<=T;ti++)
	{
		int sum=0;
		for(int i=0;i<4;i++)
		{
			int x;
			scanf("%d",&x);
			sum+=x;
		}
		int sum2=0;
		int Min=1000;
		for(int i=0;i<3;i++)
		{
			int x;
			scanf("%d",&x);
			Min=min(Min,x);
			sum2+=x;
		}
		sum = sum*2+sum2-Min;
		printf("Case %d: ",ti);
		if(sum>=90*2)printf("A");
		else if(sum>=80*2)printf("B");
		else if(sum>=70*2)printf("C");
		else if(sum>=60*2)printf("D");
		else printf("F");
		printf("\n");
	}
	return 0;
}

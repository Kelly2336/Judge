#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    
    for(int i = 0; i < n ;i+=1)
    {
		int sum,sub;
		scanf("%d %d",&sum,&sub);
		int a=sub+sum;
		if(sum>=sub&&a%2==0)
		{
			a=a/2;
			int b=sum-a;
			printf("%d %d\n",a,b);
		}
		else printf("impossible\n");
    }
    return 0;
}

#include <stdio.h>

int OddSum(int a,int b)
{
	int sum=0;
	for(int i=a;i<=b;i++)
	{
		if(i%2==1)sum+=i;
	}
	return sum;
}
// -------------------------------------------------------
int main()
{
    int T;
    scanf("%d", &T);
    for(int i=1 ; i<=T ; i+=1)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("Case %d: %d\n", i, OddSum(a, b));
    }
    return 0;
}

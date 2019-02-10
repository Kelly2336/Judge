#include<stdio.h>
#include<cmath>
using namespace std;
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        double sq=sqrt(n);
        int sum=1;
        for(int i=2;i<sq;i++)
        {
            if(n%i==0)
            {
                sum+=i+n/i;
            }
        }
        if(int(sq)*int(sq)==n)sum+=int(sq);
        if(sum>n)printf("abundant\n");
        else if(sum<n)printf("deficient\n");
        else printf("perfect\n");
    }
    return 0;
}

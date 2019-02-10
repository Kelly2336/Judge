#include<stdio.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        n=(63*n+7492)*5-498;
        if(n<0)n*=-1;
        printf("%d\n",n%100/10);
    }
    return 0;
}

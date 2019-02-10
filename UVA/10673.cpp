#include<stdio.h>
#include<cmath>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int x,k;
        scanf("%d%d",&x,&k);
        int f=x-floor(x/k)*k;
        printf("%d %d\n",k-f,f);
    }
    return 0;
}

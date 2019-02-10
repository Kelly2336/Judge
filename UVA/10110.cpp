#include<stdio.h>
#include<cmath>
int main()
{
    unsigned int n;
    while(1)
    {
        scanf("%u",&n);
        if(n==0)break;
        int s=sqrt(n);
        if(s*s==n)printf("yes\n");
        else printf("no\n");
    }
    return 0;
}

#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        int C;
        int d;
        scanf("%d%d",&C,&d);
        printf("Case %d: %.2f\n",i,C+d*5/9.0);
    }
    return 0;
}

#include<stdio.h>
int main()
{
    int M,N;
    while(scanf("%d%d",&M,&N)==2)
    {
        int ans=0;
        ans+=M-1;
        ans+=M*(N-1);
        printf("%d\n",ans);
    }
    return 0;
}

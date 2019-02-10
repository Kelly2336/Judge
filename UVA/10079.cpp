#include<stdio.h>
int main()
{
    int N;
    while(1)
    {
        scanf("%d",&N);
        if(N<0)break;
        long long int n=N;
        long long int ans=1;
        if(n%2)ans+=(n+1)/2*n;
        else ans+=n/2*(1+n);
        printf("%lld\n",ans);
    }
    return 0;
}

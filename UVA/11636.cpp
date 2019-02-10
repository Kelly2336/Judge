#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,cas=0;
    while(1)
    {
        scanf("%d",&n);
        if(n<0)break;
        int ans;
        if(n==1)ans=0;
        else ans=ceil(log2(n));
        printf("Case %d: %d\n",++cas,ans);
    }
    return 0;
}

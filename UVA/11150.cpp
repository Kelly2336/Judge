#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ans[205];
    memset(ans,0,sizeof(ans));
    ans[3]=1;
    for(int i=4;i<205;i++)
    {
        ans[i]=ans[i/3+i%3]+i/3;
    }
    int n;
    while(scanf("%d",&n)==1)
    {
        printf("%d\n",ans[n+1]+n);
    }
    return 0;
}

#include<stdio.h>
#include<queue>
#include<iostream>
using namespace std;
int main()
{
    int n,s;
    while(scanf("%d%d",&n,&s)==2)
    {
        queue<int> q;
        int sum=0,len=0,ans=n+1;
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            sum+=x;
            len++;
            q.push(x);
            while(sum>=s)
            {
                ans=min(ans,len);
                sum-=q.front();
                q.pop();
                len--;
            }
        }
        if(ans>n)ans=0;
        printf("%d\n",ans);
    }
    return 0;
}

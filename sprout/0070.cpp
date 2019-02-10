//Add all
//Greedy+heap
#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
typedef long long LL;
int main()
{
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        priority_queue<LL,vector<LL>,greater<LL> > q;
        while(!q.empty())q.pop();
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            q.push(x);
        }
        LL ans=0;
        while(1)
        {
            LL a=q.top();
            q.pop();
            if(q.empty())break;
            LL b=q.top();
            q.pop();
            LL c=a+b;
            ans+=c;
            q.push(c);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

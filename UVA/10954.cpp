#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;
typedef long long int LL;
int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(!n)break;
        priority_queue<LL,vector<LL>,greater<LL> > pq;
        int a[5010];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            pq.push(a[i]);
        }
        LL ans=0;
        for(int i=1;i<n;i++)
        {
            LL a=pq.top();
            pq.pop();
            LL b=pq.top();
            pq.pop();
            LL c=a+b;
            ans+=c;
            pq.push(c);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

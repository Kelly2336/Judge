#include<stdio.h>
#include<vector>
#include<queue>
#include<set>
using namespace std;
int c[4]={2,3,5,7};
typedef long long LL;
LL ans[5845];

int main()
{
    priority_queue< LL , vector<LL> ,greater<LL> > pq;
    set<LL> s;
    pq.push(1);
    s.insert(1);

    for(int i=1;i<=5842;i++)
    {
        ans[i]=pq.top();
        pq.pop();
        for(int k=0;k<4;k++)
        {
            LL x=ans[i]*c[k];
            if(s.count(x)==0)
            {
                s.insert(x);
                pq.push(x);
            }
        }
    }

    int n;
    while(scanf("%d",&n)==1&&n)
    {
        printf("The %d",n);
        if(n%10==1&&n%100!=11)printf("st");
        else if(n%10==2&&n%100!=12)printf("nd");
        else if(n%10==3&&n%100!=13)printf("rd");
        else printf("th");
        printf(" humble number is %lld.\n",ans[n]);
    }

    return 0;
}

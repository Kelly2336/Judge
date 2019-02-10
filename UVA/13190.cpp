#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;

typedef pair<int,int> P;

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        priority_queue<P,vector<P>,greater<P> > pq;
        while(!pq.empty())pq.pop();
        int tm[3005];
        char name[3005][20];
        for(int i=0;i<n;i++)
        {
            P p;
            scanf("%s %d",name[i],&tm[i]);
            p.first=tm[i];
            p.second=i;
            pq.push(p);
        }
        while(k--)
        {
            P p=pq.top();
            pq.pop();
            int i=p.second;
            printf("%d %s\n",p.first,name[i]);
            p.first+=tm[i];
            pq.push(p);
        }
    }
    return 0;
}

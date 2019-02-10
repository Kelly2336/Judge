//円円賣漢堡
//單調隊列
#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k,c;
        scanf("%d%d%d",&n,&k,&c);
        long long int val[100005];
        for(int i=1;i<=n;i++)scanf("%lld",&val[i]);
        long long int MAX=val[1];
        long long int dp[100005]={0};
        deque<long long int> dq;
        while(!dq.empty()) dq.pop_back();
        dq.push_back(0);
        for(int i=1;i<=n;i++)
        {
            if( i>k && dq.front()==dp[i-k-1]+c*(i-k-1) ) dq.pop_front();
            long long int t=dq.front()-c*i;
            if(t<0)t=0;
            dp[i]=t+val[i];
            if(dp[i]>MAX) MAX=dp[i];
            while( !dq.empty() && dq.back()<dp[i]+c*i ) dq.pop_back();
            dq.push_back(dp[i]+c*i);
        }
        printf("%lld\n",MAX);
    }
    return 0;
}
/*
2
4 2 1
-1 3 -2 4
4 2 2
-1 3 -2 4
*/

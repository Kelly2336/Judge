//0/1 knapsack
//backtracking
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;
int main()
{
    int N,T;
    int dp[20000];
    while(scanf("%d%d",&N,&T)==2)
    {
        memset(dp,-1,sizeof(int)*(N+1));
        dp[0]=0;
        int s,sum=0,m=0;
        while(T--)
        {
            scanf("%d",&s);
            sum+=s;
            if(sum>N)sum=N;
            for(int i=sum; i>=s; i--)
            {
                if(dp[i]==-1&&dp[i-s]!=-1)
                {
                    dp[i]=s;
                    if(i>m)m=i;
                }
            }
        }
        int ans=m;
        vector<int> v;
        v.clear();
        while(dp[ans]!=0)
        {
            v.push_back(dp[ans]);
            ans-=dp[ans];
        }
        for(int i=v.size()-1;i>=0;i--)
        {
            printf("%d ",v[i]);
        }
        printf("sum:%d\n",m);
    }
    return 0;
}

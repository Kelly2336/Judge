//0/1knapsack
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main()
{
    int T;
    scanf("%d ",&T);
    string s;
    stringstream ss;
    bool dp[210];
    while(T--)
    {
        getline(cin,s);
        ss.clear();
        ss.str(s);
        int sum=0;
        int v;
        memset(dp,0,sizeof(dp));
        dp[0]=true;
        while(ss>>v)
        {
            sum+=v;
            for(int i=sum;i>=v;i--)
            {
                if(dp[i-v])dp[i]=true;
            }
        }
        if(sum%2==0&&dp[sum/2])printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

//DP不優
//先二分搜答案，再二分搜前綴和
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int N,K,x;
    int sum[650];//prefix sum
    while(scanf("%d%d",&N,&K)==2)
    {
        int MAX=0;
        scanf("%d",&sum[0]);
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&x);
            sum[i]=sum[i-1]+x;
            MAX=max(MAX,x);
        }
        //binary_search
        int small=MAX,big=sum[N];
        int ans=sum[N];
        sum[N+1]=1e9;
        while(small<=big)
        {
            int now=0;
            int last=0;
            int mid=(small+big)/2;
            int cnt=0;
            while(now<N+1)//O(KlogN)
            {
                now=upper_bound(sum+now,sum+N+2,last+mid)-sum;
                last=sum[now-1];
                cnt++;
                if(cnt>K)break;
            }
            if(now==N+1)
            {
                big=mid-1;
                ans=min(ans,mid);
            }
            else small=mid+1;
        }
        printf("%d\n",ans);
    }
    return 0;
}

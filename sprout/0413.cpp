//小朋友上樓梯
//二分搜
#include<stdio.h>
#include<algorithm>
using namespace std;
long long int d[200005];
int N,K;
long long D;
bool solve(long long int h)
{
    long long int now=0;
    int di=0;
    int k=0;
    //printf("%d:\n",h);
    while(k<=K)
    {
        while( d[di]<=now+h && di<=N+1 )di++;
        if(now==d[di-1])return false;
        now=d[di-1];
        k++;
        //printf("%d %d\n",k,now);
        if(now>=D)return true;
    }
    return false;
}
int main()
{
    scanf("%d%d%d",&N,&K,&D);
    for(int i=1;i<=N;i++)scanf("%d",&d[i]);
    d[0]=0;
    d[N+1]=D;
    sort(d,d+N+2);

    long long int small=1;
    long long int big=D;
    long long int mid;
    int ans=D;
    while(small<=big)
    {
        mid=(small+big)/2;
        if( solve(mid) )
        {
            if(mid<ans)ans=mid;
            big=mid-1;
        }
        else small=mid+1;
    }
    printf("%d\n",ans);
    return 0;
}

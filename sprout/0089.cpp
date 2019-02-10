//誰先晚餐
//Greedy
#include<stdio.h>
#include<algorithm>
using namespace std;
typedef pair<int,int> P;
int main()
{
    while(1)
    {
        int n;
        scanf("%d",&n);
        if(!n)break;
        P t[10005];
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&t[i].second,&t[i].first);
        }
        sort(t,t+n);
        reverse(t,t+n);
        int ans=0;
        int cook=0;
        for(int i=0;i<n;i++)
        {
            cook+=t[i].second;
            if(ans<cook+t[i].first)ans=cook+t[i].first;
        }
        printf("%d\n",ans);
    }
    return 0;
}

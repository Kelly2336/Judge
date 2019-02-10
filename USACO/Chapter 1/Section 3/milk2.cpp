/*
ID: whitech1
TASK: milk2
LANG: C++
*/
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int,int> ii;
int main()
{
    freopen("milk2.in","r",stdin);
    freopen("milk2.out","w",stdout);
    int n;
    scanf("%d",&n);
    ii t[5100];
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&t[i].first,&t[i].second);
    }
    sort(t,t+n);
    int start=t[0].first;
    int ending=t[0].second;
    int ans1=ending-start;
    int ans2=0;
    for(int i=1;i<n;i++)
    {
        if(t[i].first<=ending)
        {
            ending=max(ending,t[i].second);
        }
        else
        {
            ans1=max(ans1,ending-start);
            start=t[i].first;
            ans2=max(ans2,start-ending);
            ending=t[i].second;
        }
    }
    printf("%d %d\n",ans1,ans2);
    return 0;
}

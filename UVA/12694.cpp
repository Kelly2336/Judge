#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
#include<iostream>
using namespace std;
struct Time
{
    int s;
    int f;
};

int cmp(const void* p,const void* q)
{
    Time a = *(Time*)p;
    Time b = *(Time*)q;
    return a.f - b.f;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        Time t[20];
        int n=0;
        while(1)
        {
            scanf("%d%d",&t[n].s,&t[n].f);
            if(!t[n].s&&!t[n].f)break;
            n++;
        }
        qsort(t,n,sizeof(Time),cmp);
        int right=t[0].f;
        int ans=1;
        for(int i=1;i<n;i++)
        {
            if(t[i].s>=right)
            {
                ans++;
                right=t[i].f;
            }
        }
        printf("%d",ans);
        cout<<endl;
    }
    return 0;
}

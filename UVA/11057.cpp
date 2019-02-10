#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    int cas=0;
    while(scanf("%d",&n)==1&&n)
    {
        bool book[2000010]={0};
        int a[10005];
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        scanf("%d",&m);
        int ans=100000000;
        for(int i=0;i<n;i++)
        {
            if(a[i]>m)continue;//RE
            int t=m-a[i];
            if(book[t])
            {
                t-=a[i];
                if(t<0)t=-t;
                if(t<ans)ans=t;
            }
            book[a[i]]=true;
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n",(m-ans)/2,(m+ans)/2);
    }
    return 0;
}

#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int n,d,r;
    while(scanf("%d%d%d",&n,&d,&r)==3&&(n!=0||d!=0||r!=0))
    {
        int ans=0;
        int mor[150],aft[150];
        for(int i=0;i<n;i++)scanf("%d",&mor[i]);
        for(int i=0;i<n;i++)scanf("%d",&aft[i]);
        sort(mor,mor+n);
        sort(aft,aft+n);

        for(int i=0;i<n;i++)
        {
            int time=mor[i]+aft[n-1-i]-d;
            if(time>0)
            {
                ans+=time;
            }
        }
        printf("%d\n",ans*r);
    }
    return 0;
}

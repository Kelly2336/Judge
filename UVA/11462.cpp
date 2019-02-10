#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    while(1)
    {
        int n;
        scanf("%d",&n);
        if(!n)break;
        int a[105];
        memset(a,0,sizeof(a));
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            a[x]++;
        }
        int t=0;
        for(int i=1;i<=100;i++)
        {
            while(a[i]--)
            {
                if(t)printf("%d ",t);
                t=i;
            }
        }
        printf("%d\n",t);
    }
    return 0;
}

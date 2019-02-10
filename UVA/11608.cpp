#include<stdio.h>
using namespace std;
int main()
{
    int n,cas=0;
    while(1)
    {
        int sum[15];
        scanf("%d",&sum[0]);
        if(sum[0]<0)break;
        printf("Case %d:\n",++cas);
        for(int i=1;i<=12;i++)
        {
            scanf("%d",&sum[i]);
            sum[i]+=sum[i-1];
        }
        int used=0;
        for(int i=1;i<=12;i++)
        {
            int a;
            scanf("%d",&a);
            if(a+used<=sum[i-1])
            {
                printf("No problem! :D\n");
                used+=a;
            }
            else printf("No problem. :(\n");
        }
    }
    return 0;
}

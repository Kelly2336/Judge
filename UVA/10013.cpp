#include<stdio.h>
#include<string.h>
using namespace std;
int sum[1000005];
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int m;
        scanf("%d",&m);
        int a,b;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            sum[i]=a+b;
        }
        for(int i=m-1;i>0;i--)
        {
            sum[i-1]+=sum[i]/10;
            sum[i]%=10;
        }
        for(int i=0;i<m;i++)
            printf("%d",sum[i]);
        printf("\n");
        if(n)printf("\n");
    }
    return 0;
}

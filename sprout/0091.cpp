//調校高棕櫚！
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n;
        scanf("%lld",&n);
        if(n==1)
        {
            printf("1\n");
            continue;
        }
        int cnt[10];
        memset(cnt,0,sizeof(cnt));
        for(int i=9;i>=2;i--)
        {
            while(n%i==0)
            {
                n/=i;
                cnt[i]++;
            }
        }
        if(n!=1)
        {
            printf("-1\n");
        }
        else
        {
            for(int i=2;i<=9;i++)
            {
                while(cnt[i]--)printf("%d",i);
            }
            printf("\n");
        }
    }
    return 0;
}

//Greedy
#include<stdio.h>
using namespace std;
int main()
{
    int n,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        if(n==0)printf("-1\n");
        else if(n<=9)printf("%d\n",n);
        else
        {
            int cnt[10]={0};
            for(int i=9;i>=2;i--)
            {
                while(n%i==0)
                {
                    n/=i;
                    cnt[i]++;
                }
            }
            if(n>1)printf("-1\n");
            else
            {
                for(int i=2;i<=9;i++)
                {
                    while(cnt[i])
                    {
                        printf("%d",i);
                        cnt[i]--;
                    }
                }
                printf("\n");
            }
        }
    }
    return 0;
}

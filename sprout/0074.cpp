//円円攻略黃河
//Greedy
#include<stdio.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int len=1;
        int now;
        scanf("%d",&now);
        n--;
        while(n--)
        {
            int x;
            scanf("%d",&x);
            if(len%2==1)//H
            {
                if(x<now)len++;
                now=x;
            }
            else//L
            {
                if(x>now)len++;
                now=x;
            }
        }
        if(len%2==0)len--;
        printf("%d\n",len);
    }
    return 0;
}

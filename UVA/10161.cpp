#include<stdio.h>
#include<cmath>
using namespace std;
int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(!n)break;
        int q=sqrt(n);
        int k=n-q*q;
        int x=1,y=1;
        if(q%2)
        {
            y=q;
            if(k)
            {
                k--;
                y++;
            }
            for(int i=0;i<q;i++)
            {
                if(!k)break;
                x++;
                k--;
            }
            while(k--)
            {
                y--;
            }
        }
        else
        {
            x=q;
            if(k)
            {
                k--;
                x++;
            }
            for(int i=0;i<q;i++)
            {
                if(!k)break;
                y++;
                k--;
            }
            while(k--)
            {
                x--;
            }
        }
        printf("%d %d\n",x,y);
    }
    return 0;
}

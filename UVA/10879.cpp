#include<stdio.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    for(int h=1;h<=n;h++)
    {
        int k;
        scanf("%d",&k);
        int i=2;
        while(1)
        {
            if(k%i==0)
            {
                printf("Case #%d: %d = %d * %d = ",h,k,i,k/i);
                break;
            }
            i++;
        }
        while(++i)
        {
            if(k%i==0)
            {
                printf("%d * %d\n",i,k/i);
                break;
            }
        }
    }
    return 0;
}

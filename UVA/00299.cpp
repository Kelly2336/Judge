#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[60];
        for(int i=0; i<n; i++)scanf("%d",&a[i]);
        int time=0;
        for(int i=0; i<n; i++)
        {
            int time2=0;
            for(int j=0; j<n-1-i; j++)
            {
                if(a[j]>a[j+1])
                {
                    swap(a[j],a[j+1]);
                    time2++;
                }
            }
            if(time2==0)break;
            time+=time2;
        }
        //for(int i=0;i<n;i++)printf("%d ",a[i]);
        printf("Optimal train swapping takes %d swaps.\n",time);
    }
    return 0;
}

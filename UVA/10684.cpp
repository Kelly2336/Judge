#include<stdio.h>
using namespace std;
int main()
{
    int n;
    int a[10050];
    while(scanf("%d",&n)==1&&n)
    {
        for(int i=0;i<n;i++)scanf("%d",&a[i]);
        int sum=0;
        int max=0;
        for(int i=0;i<n;i++)
        {
            sum+=a[i];
            if(sum>max)max=sum;
            if(sum<0)sum=0;
        }
        if(max<=0)printf("Losing streak.\n");
        else printf("The maximum winning streak is %d.\n",max);
    }
    return 0;
}

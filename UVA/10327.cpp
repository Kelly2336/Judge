//bubble sort
#include<stdio.h>
using namespace std;
int main()
{
    int n;
    int a[1005];
    while(scanf("%d",&n)==1)
    {
        int ans=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            for(int j=0;j<i;j++)
            {
                if(a[j]>a[i])ans++;
            }
        }
        printf("Minimum exchange operations : %d\n",ans);
    }
    return 0;
}

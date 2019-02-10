#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int a[600];
    while(n--)
    {
        int i=0;
        scanf("%d",&i);
        for(int j=0;j<i;j++)scanf("%d",&a[j]);
        sort(a,a+i);
        int s=a[i/2];
        int sum=0;
        for(int j=0;j<i/2;j++)
        {
            sum+=s-a[j];
        }
        for(int j=i/2;j<i;j++)
        {
            sum+=a[j]-s;
        }
        printf("%d\n",sum);
    }
    return 0;
}

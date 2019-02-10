#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int d;
        scanf("%d",&d);
        int a[20000];
        for(int i=0;i<d;i++)scanf("%d",&a[i]);
        sort(a,a+d);
        reverse(a,a+d);
        int sum=0;
        for(int i=2;i<d;i+=3)sum+=a[i];
        printf("%d\n",sum);
    }
    return 0;
}

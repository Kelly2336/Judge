#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    printf("Lumberjacks:\n");
    while(n--)
    {
        int a[10];
        for(int i=0;i<10;i++)scanf("%d",&a[i]);
        bool order=true;
        for(int i=0;i<8;i++)
        {
            if(a[i]<a[i+1]!=a[i+1]<a[i+2])
            {
                order=false;
                break;
            }
        }
        if(order)printf("Ordered\n");
        else printf("Unordered\n");
    }
    return 0;
}

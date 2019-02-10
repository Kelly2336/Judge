#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a[3];
        for(int i=0;i<3;i++)
            scanf("%d",&a[i]);
        sort(a,a+3);
        if(a[0]+a[1]>a[2]&&a[2]>0&&a[1]>0&&a[0]>0)printf("OK\n");
        else printf("Wrong!!\n");
    }
    return 0;
}

#include<stdio.h>
int main()
{
    char a[7][10]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
    int f[12]={6,2,2,5,7,3,5,1,4,6,2,4};
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int m,d;
        scanf("%d%d",&m,&d);
        int ans=(f[m-1]+(d-1))%7;
        printf("%s\n",a[ans]);
    }
    return 0;
}

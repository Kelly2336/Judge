#include<stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a;
        int min=99,max=0;
        while(n--)
        {
            scanf("%d",&a);
            if(a>max)max=a;
            if(a<min)min=a;
        }
        printf("%d\n",2*(max-min));
    }
    return 0;
}

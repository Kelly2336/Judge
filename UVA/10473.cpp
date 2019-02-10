#include<stdio.h>
int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(n!=0)
        {
            if(n<0)break;
            printf("0x%X",n);
            printf("\n");
        }
        else
        {
            char c;
            while(c=getchar())
            {
                if(c=='x')break;
            }
            scanf("%X",&n);
            printf("%d",n);
            printf("\n");
        }
    }
    return 0;
}

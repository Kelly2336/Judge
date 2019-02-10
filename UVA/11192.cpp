#include<stdio.h>
#include<cstring>
int main()
{
    while(1)
    {
        int r;
        scanf("%d",&r);
        if(!r)break;
        char s[120];
        scanf(" %s",s+1);
        int len=strlen(s+1);
        int n=len/r;
        for(int i=0;i<r;i++)
        {
            for(int j=n;j>=1;j--)
            {
                printf("%c",s[i*n+j]);
            }
        }
        printf("\n");
    }
    return 0;
}

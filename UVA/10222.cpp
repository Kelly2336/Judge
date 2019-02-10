#include<stdio.h>
#include<cstring>
int main()
{
    char s[1000];
    char c[]="qwertyuiop[]asdfghjkl;'zxcvbnm,.\/";
    gets(s);
    int len=strlen(s);
    int lc=strlen(c);
    for(int i=0;i<len;i++)
    {
        if(s[i]==' ')
        {
            printf(" ");
            continue;
        }
        for(int j=0;j<lc;j++)
        {
            if(c[j]==s[i])
            {
                printf("%c",c[j-2]);
                break;
            }
        }
    }
    printf("\n");
    return 0;
}

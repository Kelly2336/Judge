#include<stdio.h>
#include<string.h>
int main()
{
    char a[30];
    char rev[]="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
    while(scanf("%s",a)>=1)
    {
        int len=strlen(a);
        bool palin=true;
        bool mirro=true;
        for(int i=0;i<len/2;i++)
        {
            if(a[i]!=a[len-1-i])
            {
                palin=false;
                break;
            }
        }
        for(int i=0;i<len/2+1;i++)
        {
            char newa;
            if(a[i]<='Z'&&a[i]>='A')newa=rev[a[i]-'A'];
            else newa=rev[a[i]-'1'+26];
            if(a[len-1-i]!=newa)
            {
                mirro=false;
                break;
            }
        }
        printf("%s -- is ",a);
        if(palin)
        {
            if(mirro)printf("a mirrored palindrome.\n");
            else printf("a regular palindrome.\n");
        }
        else
        {
            if(mirro)printf("a mirrored string.\n");
            else printf("not a palindrome.\n");
        }
        printf("\n");
    }
    return 0;
}

#include<stdio.h>
#include<cstring>
char s[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
int len=strlen(s);
int main()
{
    char c;
    while((c=getchar())!=EOF)
    {
        bool unfind=true;
        for(int i=1;i<len;i++)
        {
            if(c==s[i])
            {
                putchar(s[i-1]);
                unfind=false;
                break;
            }
        }
        if(unfind)putchar(c);
    }
    return 0;
}

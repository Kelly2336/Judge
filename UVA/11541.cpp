#include<stdio.h>
#include<ctype.h>
#include<cstring>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=1;i<=T;i++)
    {
        printf("Case %d: ",i);
        char s[500];
        scanf("%s",s);
        int len=strlen(s);
        char a='\0';
        int time=0;
        for(int i=0;i<len;i++)
        {
            if(isupper(s[i]))
            {
                for(int j=0;j<time;j++)printf("%c",a);
                a=s[i];
                time=0;
            }
            else if(isdigit(s[i]))
            {
                time=time*10+s[i]-'0';
            }
        }
        for(int j=0;j<time;j++)printf("%c",a);
        printf("\n");
    }
    return 0;
}

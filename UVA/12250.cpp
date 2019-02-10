#include<stdio.h>
#include<cstring>
int main()
{
    char h[6][15]={"HELLO","HOLA","HALLO","BONJOUR","CIAO","ZDRAVSTVUJTE"};
    char c[7][10]={"ENGLISH","SPANISH","GERMAN","FRENCH","ITALIAN","RUSSIAN","UNKNOWN"};
    int cas=0;
    while(1)
    {
        char s[20];
        scanf(" %s",s);
        if(s[0]=='#'&&s[1]=='\0')break;
        cas++;
        printf("Case %d: " ,cas);
        int ci=6;
        for(int i=0;i<6;i++)
        {
            if(strcmp(s,h[i])==0)
            {
                ci=i;
                break;
            }
        }
        printf("%s\n",c[ci]);
    }
    return 0;
}

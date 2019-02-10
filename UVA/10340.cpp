#include<stdio.h>
#include<string.h>
char s[500010],t[500010];
int main()
{
    while(1)
    {
        int lens=0,lent=0;
        char c='0';
        while(scanf("%c",&c)>=1)
        {
            //c=getchar();
            if(c==' '||c=='\n')
            {
                s[lens]='\0';
                break;
            }
            s[lens]=c;
            lens+=1;
        }
        if(lens==0)break;
        while(1)
        {
            c=getchar();
            if(c==' '||c=='\n')
            {
                t[lent]='\0';
                break;
            }
            t[lent]=c;
            lent+=1;
        }
        /*
        for(int i=0;i<lens;i++)
        {
            printf("%c",s[i]);
        }
        for(int i=0;i<lent;i++)
        {
            printf("%c",t[i]);
        }
        */
        int l=0;
        bool sub=false;
        for(int i=0;i<lent;i++)
        {
            if(t[i]==s[l])
            {
                l++;
                if(l==lens)
                {
                    sub=true;
                    break;
                }
            }
        }
        if(sub)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

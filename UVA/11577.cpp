#include<stdio.h>
#include<cstring>
#include<ctype.h>
int main()
{
    int n;
    char s;
    scanf("%d",&n);
    while(n--)
    {
        int a[26]={0};
        memset(a,0,sizeof(a));
        scanf("%c",&s);
        while(1)
        {
            int i=tolower(s)-'a';
            if(i<26&&i>=0)a[i]++;
            scanf("%c",&s);
            if(s=='\n')break;
        }
        int max=0;
        for(int i=0;i<26;i++)
        {
            if(a[i]>max)max=a[i];
            //printf("%d %c\n",a[i],'a'+i);
        }
        for(int i=0;i<26;i++)
        {
            if(a[i]==max)printf("%c",i+'a');
        }
        printf("\n");
    }
    return 0;
}

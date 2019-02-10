#include<stdio.h>
#include<string.h>
int main()
{
    char a[55];
    while(1)
    {
        scanf("%s",a);
        if(a[0]=='#')break;
        int len=strlen(a);
        int i;
        for(i=len-1;i>0;i--)
        {
            if(a[i]>a[i-1])break;
        }
        if(i==0)
        {
            printf("No Successor\n");
        }
        else
        {
            int s[26];
            memset(s,0,sizeof(s));
            for(int j=i-1;j<len;j++)
            {
                s[a[j]-'a']++;
            }
            int key=0,t=0;
            for(int j=a[i-1]-'a'+1;j<26;j++)
            {
                if(s[j]>0)key++;
                if(key)
                {
                    s[j]--;
                    t=j;
                    break;
                }
            }
            for(int j=0;j<i-1;j++)
            {
                printf("%c",a[j]);
            }
            printf("%c",'a'+t);
            for(int j=0;j<26;j++)
            {
                for(int k=0;k<s[j];k++)
                {
                    printf("%c",'a'+j);
                }
            }
            printf("\n");
        }
    }
    return 0;
}

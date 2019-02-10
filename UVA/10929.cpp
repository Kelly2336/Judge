#include<stdio.h>
#include<cstring>
int main()
{
    while(1)
    {
        char s[1010];
        scanf("%s",s);
        int len=strlen(s);
        if(s[0]=='0'&&len==1)break;
        int sum=0;
        for(int i=0;i<len;i++)
        {
            if(i%2==0)sum+=s[i]-'0';
            else sum-=s[i]-'0';
        }
        if(sum<0)sum*=-1;
        if(sum%11==0)printf("%s is a multiple of 11.\n",s);
        else printf("%s is not a multiple of 11.\n",s);
    }
    return 0;
}

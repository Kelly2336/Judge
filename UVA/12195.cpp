#include<stdio.h>
#include<cstring>
int main()
{
    char s[200];
    char a[]="WHQESTX";
    int len[7]= {64,32,16,8,4,2,1};
    while(scanf("%s",s)>0&&s[0]!='*')
    {
        int L=strlen(s);
        int sum=0;
        int legal=0;
        for(int i=0; i<L; i++)
        {
            if(s[i]=='/')
            {
                if(sum==64)
                {
                    legal++;
                }
                sum=0;
            }
            else
            {
                for(int j=0;j<7;j++)
                {
                    if(a[j]==s[i])
                    {
                        sum+=len[j];
                    }
                }
            }
        }
        printf("%d\n",legal);
    }
    return 0;
}

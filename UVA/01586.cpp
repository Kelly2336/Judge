#include<stdio.h>
#include<cstring>
#include<ctype.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(; n>0; n--)
    {
        char s[100];
        scanf("%s",s);
        int len=strlen(s);
        double sum=0;
        char a=s[0];
        int num=0;
        char atom[]="CHON";
        double weight[]= {12.01,1.008,16.00,14.01};
        for(int i=1; i<len; i++)
        {
            if(isupper(s[i]))
            {
                if(num==0)num=1;
                for(int j=0; j<4; j++)
                {
                    if(atom[j]==a)
                    {
                        sum+=weight[j]*num;
                        break;
                    }
                }
                a=s[i];
                num=0;
            }
            else num=num*10+s[i]-'0';
        }

        if(num==0)num=1;
        for(int j=0; j<4; j++)
        {
            if(atom[j]==a)
            {
                sum+=weight[j]*num;
                break;
            }
        }

        printf("%.3lf\n",sum);
    }
    return 0;
}

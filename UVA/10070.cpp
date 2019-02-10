#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
    int c=0;
    char s[10000];
    while(scanf("%s",&s)>0)
    {
        if(c++)printf("\n");
        int len=strlen(s);
        bool leap=false,h=false,b=false;
        int n=0;
        for(int i=max(0,len-4);i<len;i++)
        {
            n=n*10+s[i]-'0';
        }
        if((n%4==0&&n%100)||(n%400==0)){leap=true;printf("This is leap year.\n");}
        if(n%5==0)
        {
            int three=0;
            for(int i=0;i<len;i++)three+=(s[i]-'0');
            int ele=0;
            for(int i=0;i<len;i+=2)ele+=(s[i]-'0');
            if(three%3==0){h=true;printf("This is huluculu festival year.\n");}
            if(leap&&(three-2*ele)%11==0){b=true;printf("This is bulukulu festival year.\n");}
        }
        if(!leap&&!h&&!b)printf("This is an ordinary year.\n");
    }
    return 0;
}

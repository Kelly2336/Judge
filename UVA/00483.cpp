#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char s[1000];
    while(1)
    {
        cin.getline(s,1000);
        if(cin.fail())break;
        int len=strlen(s);
        s[len]=' ';
        int last=0;
        for(int i=0; i<len; i++)
        {
            if(s[i]==' ')
            {
                for(int j=i-1; j>=last; j--)
                {
                    printf("%c",s[j]);
                }
                printf(" ");
                last=i+1;
            }
        }
        for(int j=len-1; j>=last; j--)
        {
            printf("%c",s[j]);
        }
        printf("\n");
    }
    return 0;
}

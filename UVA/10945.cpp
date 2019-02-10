#include<stdio.h>
#include<string.h>
#include<iostream>
#include<ctype.h>
using namespace std;
int main()
{
    while(1)
    {
        char s[200000];
        cin.getline(s,200000);
        if(strcmp(s,"DONE")==0)break;
        bool pal=true;
        for(int i=0,j=strlen(s)-1;i<j;i++,j--)
        {
            while(i<j&&!isalpha(s[i]))i++;
            while(i<j&&!isalpha(s[j]))j--;
            if(i>=j)break;
            if(tolower(s[i])!=tolower(s[j]))
            {
                pal=false;
                break;
            }
        }
        if(pal)printf("You won\'t be eaten!\n");
        else printf("Uh oh..\n");
    }
    return 0;
}

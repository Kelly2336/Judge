#include<stdio.h>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    char s[500];
    while(n--&&scanf(" %s",s)>0)
    {
        int len=strlen(s);
        if(!(strcmp(s,"1")&&strcmp(s,"4")&&strcmp(s,"78")))printf("+\n");
        else if(s[len-2]=='3'&&s[len-1]=='5')printf("-\n");
        else if(s[0]=='9'&&s[len-1]=='4')printf("*\n");
        else if(s[0]=='1'&&s[1]=='9'&&s[2]=='0')printf("?\n");
    }
    return 0;
}

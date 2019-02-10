#include<stdio.h>
#include<stack>
#include<string.h>
#include<iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    char a;
    scanf("%c",&a);
    while(n--)
    {
        char s[140];
        cin.getline(s,140);
        int len=strlen(s);
        stack<char> a;
        while(!a.empty())
        {
            a.pop();
        }
        for(int i=0;i<len;i++)
        {
            if(!a.empty())
            {
                if(a.top()=='('&&s[i]==')')a.pop();
                else if(a.top()=='['&&s[i]==']')a.pop();
                else a.push(s[i]);
            }
            else a.push(s[i]);
        }
        if(a.empty())printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}

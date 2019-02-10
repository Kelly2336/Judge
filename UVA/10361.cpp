#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int q;
    cin>>q;
    char d;
    scanf("%c",&d);
    while(q--)
    {
        char s[120];
        char n[120];
        cin.getline(s,120);
        cin.getline(n,120);
        int ls=strlen(s);
        int ln=strlen(n);
        int a[4]={0};
        int ai=0;
        for(int i=0;i<ls;i++)
        {
            if(s[i]=='<'||s[i]=='>')
            {
                a[ai]=i;
                ai++;
            }
            else printf("%c",s[i]);
        }
        printf("\n");
        for(int i=0;i<ln;i++)
        {
            if(n[i]!='.')
            {
                printf("%c",n[i]);
            }
            else break;
        }
        for(int i=a[2]+1;i<=a[3]-1;i++)printf("%c",s[i]);
        for(int i=a[1]+1;i<=a[2]-1;i++)printf("%c",s[i]);
        for(int i=a[0]+1;i<=a[1]-1;i++)printf("%c",s[i]);
        for(int i=a[3]+1;i<ls;i++)printf("%c",s[i]);
        printf("\n");
    }
    return 0;
}

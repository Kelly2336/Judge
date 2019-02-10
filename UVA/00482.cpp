#include<stdio.h>
#include<cctype>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int p[200000];
char w[200000][30];
int main()
{
    int t;
    scanf("%d",&t);
    string s;
    stringstream ss;
    while(t--)
    {
        while(1)
        {
            getline(cin,s);
            if(cin.fail()||isdigit(s[0]))break;
        }
        ss.clear();
        ss.str(s);
        int n=0;
        while(ss>>p[n])n++;
        for(int i=0;i<n;i++)
        {
            scanf(" %s",w[p[i]]);
        }
        for(int i=1;i<=n;i++)
        {
            printf("%s\n",w[i]);
        }
        if(t)printf("\n");
    }
    return 0;
}

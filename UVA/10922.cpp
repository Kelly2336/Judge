#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;

int n;
int nine(int n)
{
    if(n==9)return 1;
    int m=0;
    while(n>0)
    {
        m+=n%10;
        n/=10;
    }
    if(m%9==0)return nine(m)+1;
    return 0;
}
int main()
{
    string a;
    while(1)
    {
        cin>>a;
        if(a=="0")break;
        int t=0;
        n=0;
        int len=a.length();
        for(int i=0;i<len;i++)
            n+=a[i]-'0';
        t+=nine(n);
        cout<<a;
        if(t>0)printf(" is a multiple of 9 and has 9-degree %d.\n",t);
        else printf(" is not a multiple of 9.\n");
    }
    return 0;
}

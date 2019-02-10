#include<stdio.h>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
#define maxn 100005
int main()
{
    int n;
    int a[maxn];
    string s;
    stringstream ss;
    while(1)
    {
        getline(cin,s);
        if(cin.fail())break;
        ss.clear();
        ss.str(s);
        int ans=0,last=0;
        int n=0;
        while(ss>>a[n])n++;
        for(int i=0;i<n;i++)
        {
            last=max(last,0)+a[i];
            ans=max(ans,last);
        }
        printf("%d\n",ans);
    }
    return 0;
}

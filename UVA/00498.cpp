#include<stdio.h>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
int main()
{
    string s1,s2;
    stringstream ss1,ss2;
    int ans[10000];
    int c[10000];
    while(1)
    {
        getline(cin,s1);
        if(cin.fail())break;
        getline(cin,s2);
        ss1.clear();
        ss2.clear();
        ss1.str(s1);
        ss2.str(s2);
        int n=0;
        while(ss1>>c[n])n++;
        int m=0;
        int x;
        while(ss2>>x)
        {
            int k=1;
            ans[m]=0;
            for(int i=n-1;i>=0;i--)
            {
                ans[m]+=c[i]*k;
                k*=x;
            }
            m++;
        }
        printf("%d",ans[0]);
        for(int i=1;i<m;i++)
            printf(" %d",ans[i]);
        printf("\n");
    }
    return 0;
}

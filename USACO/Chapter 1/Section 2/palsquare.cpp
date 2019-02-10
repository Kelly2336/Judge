/*
ID: whitech1
TASK: palsquare
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("palsquare.in","r",stdin);
    freopen("palsquare.out","w",stdout);
    int b;
    scanf("%d",&b);
    for(int i=1;i<=300;i++)
    {
        string s="";
        int n=i*i;
        while(n)
        {
            if(n%b>=10)s+=(n%b-10)+'A';
            else s+=n%b+'0';
            n/=b;
        }
        bool ispal=true;
        int len=s.length();
        for(int j=len/2;j>=0;j--)
        {
            if(s[j]!=s[len-1-j])
            {
                ispal=false;
                break;
            }
        }
        if(ispal)
        {
            string s2="";
            n=i;
            while(n)
            {
                if(n%b>=10)s2=char((n%b-10)+'A')+s2;
                else s2=char(n%b+'0')+s2;
                n/=b;
            }
            cout<<s2<<" "<<s;
            printf("\n");
        }
    }
    return 0;
}

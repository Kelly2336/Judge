/*
ID: whitech1
TASK: namenum
LANG: C++
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    FILE *file = fopen("namenum.in","r");
    long long int a;
    fscanf(file,"%lld",&a);
    freopen("dict.txt","r",stdin);
    freopen("namenum.out","w",stdout);
    int len=0;
    int c[15];
    while(a)
    {
        c[len++]=a%10;
        a/=10;
    }
    reverse(c,c+len);
    int cnt=0;
    char s[25];
    while(scanf("%s",s)>0)
    {
        int len2=strlen(s);
        if(len==len2)
        {
            int success=true;
            for(int i=0;i<len&&success;i++)
            {
                int t=s[i]-'A';if(t>'Q'-'A')t--;
                if( t/3+2 != c[i] )success=false;
            }
            if(success)
            {
                printf("%s\n",s);
                cnt++;
            }
        }
    }
    if(!cnt)printf("NONE\n");
    return 0;
}

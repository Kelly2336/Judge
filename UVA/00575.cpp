#include<stdio.h>
#include<cstring>
#include<cmath>
using namespace std;
int main()
{
    while(1)
    {
        char s[80];
        scanf("%s",s);
        if(s[0]=='0')break;
        int len=strlen(s);
        int ans=0;
        for(int i=0;i<len;i++)
        {
            ans+=(s[i]-'0')*(pow(2,len-i)-1);
        }
        printf("%d\n",ans);
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
char a[30]="22233344455566677778889999";
int main()
{
    char s[35];
    while(scanf("%s",s)>0)
    {
        for(int i=strlen(s)-1;i>=0;i--)
            if(isalpha(s[i]))
                s[i]=a[s[i]-'A'];
        printf("%s\n",s);
    }
    return 0;
}

//誒迪的字串
//Z-Algorithm
include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    char s[500005];
    scanf("%s",s);
    int z[500005];
    int bst=0;
    z[0]=0;
    int len=strlen(s);
    for(int i=1;i<len;i++)
    {
        if(z[bst]+bst<i)z[i]=0;
        else z[i]=min(z[bst]+bst-i,z[i-bst]);
        while(s[z[i]]==s[i+z[i]])z[i]++;
        if(z[i]+i>z[bst]+bst)bst=i;
        //printf("%d:%d\n",i,z[i]);
    }
    for(int i=1;i<=len;i++)
    {
        bool success=true;
        for(int j=i;j<len;j+=i)
        {
            if(z[j]<i)
            {
                success=false;
                break;
            }
        }
        if(success)
        {
            printf("%d\n",i);
            break;
        }
    }
    return 0;
}

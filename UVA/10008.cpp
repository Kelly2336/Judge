#include<stdio.h>
#include<cstring>
#include<ctype.h>
using namespace std;
int main()
{
    int a[26]={0};
    int n;
    scanf("%d",&n);
    char s;
    scanf("%c",&s);
    if(s!='\n')scanf("%c",&s);
    for(;n>0;n--)
    {
        while(scanf("%c",&s)>=1)
        {
            if(s=='\n')break;
            else if(isupper(s))a[s-'A']++;
            else if(islower(s))a[s-'a']++;
        }
    }
    for(int i=0;i<26;i++)
    {
         int max=0;
         for(int j=1;j<26;j++)
         {
             if(a[j]>a[max])max=j;
         }
         if(a[max]==0)break;
         else
         {
             printf("%c %d\n",'A'+max,a[max]);
             a[max]=0;
         }
    }
    return 0;
}

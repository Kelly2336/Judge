#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int s[110];
    for(int i=0;i<110;i++)s[i]=0;
    while(1)
    {
        char a[102];
        scanf("%s",a);
        int lena=strlen(a);
        if(strcmp(a,"0")==0)break;
        reverse(a,a+lena);
        for(int i=0;i<109;i++)
        {
            if(i<lena)s[i]+=a[i]-'0';
            if(s[i]>=10)
            {
                s[i+1]+=s[i]/10;
                s[i]%=10;
            }
        }
    }
    int k=109;
    while(s[k]==0)k--;
    for(int i=k;i>=0;i--)printf("%d",s[i]);
    printf("\n");
    return 0;
}

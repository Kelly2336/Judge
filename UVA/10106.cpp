#include<stdio.h>
#include<cstring>
using namespace std;
int main()
{
    char c[300];
    while(scanf("%s",c)>=1)
    {
        int a[300]={0},b[300]={0},s[600]={0};
        memset(a,0,300);
        memset(b,0,300);
        memset(s,0,550);
        int lena=strlen(c);
        for(int i=0;i<lena;i++)a[lena-1-i]=c[i]-'0';
        scanf("%s",c);
        int lenb=strlen(c);
        for(int i=0;i<lenb;i++)b[lenb-1-i]=c[i]-'0';

        for(int i=0;i<lena;i++)
        {
            for(int j=0;j<lenb;j++)
            {
                s[i+j]+=a[i]*b[j];
                s[i+j+1]+=s[i+j]/10;
                s[i+j]%=10;
            }
        }
        int first=0;
        for(int i=lena+lenb+1;i>0;i--)
        {
            if(!first)
            {
                if(s[i]!=0)first=1;
            }
            if(first)printf("%d",s[i]);
        }
        printf("%d",s[0]);
        printf("\n");
    }
    return 0;
}

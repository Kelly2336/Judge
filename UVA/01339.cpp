#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    char a[120],b[120];
    while(scanf("%s%s",a,b)>=2)
    {
        int cnta[26],cntb[26];
        memset(cnta,0,sizeof(cnta));
        memset(cntb,0,sizeof(cntb));
        int lena=strlen(a);
        int lenb=strlen(b);
        for(int i=0;i<lena;i++)
        {
            cnta[a[i]-'A']++;
        }
        for(int i=0;i<lenb;i++)
        {
            cntb[b[i]-'A']++;
        }
        sort(cnta,cnta+26);
        sort(cntb,cntb+26);
        bool same=true;
        for(int i=0;i<26;i++)
        {
            if(cnta[i]!=cntb[i])
            {
                same=false;
                break;
            }
        }
        if(same)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

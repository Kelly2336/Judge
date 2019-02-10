#include<stdio.h>
#include<string.h>
using namespace std;
char s[1000050];
int cnt[1000050];
int main()
{
    int n,cas=0;
    while(scanf("%s",s)!=EOF)
    {
        cas++;
        int len=strlen(s);
        if(!len)break;
        cnt[0]=0;
        for(int i=1;i<len;i++)
        {
            if(s[i]==s[i-1])cnt[i]=cnt[i-1];
            else cnt[i]=i;
        }
        printf("Case %d:\n",cas);
        int a,b;
        scanf("%d",&n);
        while(n--)
        {
            scanf("%d%d",&a,&b);
            if(cnt[a]==cnt[b])printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}

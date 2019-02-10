#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    int n,m,c;
    int cas=0;
    while(scanf("%d%d%d",&n,&m,&c)==3)
    {
        if(!n&&!m&&!c)break;
        cas++;
        int a[30];
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        int max=0;
        int sum=0;
        bool s[30];
        memset(s,0,sizeof(s));
        bool fuse=false;
        while(m--)
        {
            int i;
            scanf("%d",&i);
            if(fuse)continue;
            if(s[i])
            {
                sum-=a[i];
                s[i]=false;
            }
            else
            {
                sum+=a[i];
                s[i]=true;
                if(sum>max)max=sum;
                if(sum>c)fuse=true;
            }
        }
        printf("Sequence %d\n",cas);
        if(fuse)printf("Fuse was blown.\n");
        else printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n",max);
        printf("\n");
    }
    return 0;
}

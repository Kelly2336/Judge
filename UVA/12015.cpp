#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    for(int t=1;t<=n;t++)
    {
        printf("Case #%d:\n",t);
        char s[10][110];
        int v[10];
        int maxv=0;
        for(int i=0;i<10;i++)
        {
            scanf(" %s",s[i]);
            scanf("%d",&v[i]);
            if(v[i]>maxv)maxv=v[i];
        }
        for(int i=0;i<10;i++)
        {
            if(v[i]==maxv)printf("%s\n",s[i]);
        }
    }
    return 0;
}

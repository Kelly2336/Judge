#include<stdio.h>
#include<cstring>
int main()
{
    int m;
    scanf("%d",&m);
    for(int mi=0; mi<m; mi++)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        int v[105];
        for(int i=1; i<=n; i++)v[i]=1;
        for(int ki=0; ki<k; ki++)
        {
            int p;
            scanf("%d",&p);
            int a[105];
            bool cmp[105];
            memset(cmp,0,sizeof(cmp));

            for(int i=1; i<=p*2; i++)
            {
                scanf("%d",&a[i]);
                cmp[a[i]]=true;
            }
            char c;
            scanf(" %c",&c);

            if(c=='=')
            {
                for(int i=1; i<=n; i++)
                {
                    if(cmp[i])v[i]=0;
                }
            }
            else
            {
                if(c=='>')
                {
                    for(int i=1; i<=p; i++)
                    {
                        if(v[a[i]]==-2||!v[a[i]])v[a[i]]=0;
                        else v[a[i]]*=2;
                    }
                    for(int i=p+1; i<=p*2; i++)
                    {
                        if(v[a[i]]==2||!v[a[i]])v[a[i]]=0;
                        else v[a[i]]*=-2;
                    }
                }
                else// <
                {
                    for(int i=1; i<=p; i++)
                    {
                        if(v[a[i]]==2||!v[a[i]])v[a[i]]=0;
                        else v[a[i]]=-2;
                    }
                    for(int i=1+p; i<=p*2; i++)
                    {
                        if(v[a[i]]==-2||!v[a[i]])v[a[i]]=0;
                        else v[a[i]]=2;
                    }
                }
                for(int i=1; i<=n; i++)
                {
                    if(!cmp[i])v[i]=0;
                }
            }
        }
        int ans,ai=0;
        for(int i=1; i<=n; i++)
        {
            if(v[i]!=0)
            {
                ans=i;
                ai++;
            }
        }
        if(mi)printf("\n");
        if(ai!=1)
        {
            printf("0\n");
        }
        else printf("%d\n",ans);
    }
    return 0;
}

#include<stdio.h>
#include<cstring>
int main()
{
    int a[10000][2];
    memset(a,0,sizeof(a));
    int ai=-1;
    while(1)
    {
        int n;
        if(scanf("%d",&n)<1)break;
        bool counted=false;
        for(int i=0;i<=ai;i++)
        {
            if(a[i][0]==n)
            {
                counted=true;
                a[i][1]++;
                break;
            }
        }
        if(!counted)
        {
            ai++;
            a[ai][0]=n;
            a[ai][1]=1;
        }
    }
    for(int i=0;i<=ai;i++)
    {
        printf("%d %d\n",a[i][0],a[i][1]);
    }
    return 0;
}

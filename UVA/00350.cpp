#include<stdio.h>
#include<string.h>
using namespace std;
int t[10000000];
int main()
{
    int Z,I,M,L,cas=1;
    while(1)
    {
        scanf("%d%d%d%d",&Z,&I,&M,&L);
        if(!Z&&!I&&!M&&!L)break;
        printf("Case %d: ",cas);
        cas++;
        memset(t,-1,sizeof(t));
        t[L]=0;
        int r=1;
        while(1)
        {
            L=(Z*L+I)%M;
            if(t[L]!=-1)
            {
                printf("%d\n",r-t[L]);
                break;
            }
            t[L]=r;
            r++;
        }
    }
    return 0;
}

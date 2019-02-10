#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N,P;
        scanf("%d%d",&N,&P);
        bool work[4000];
        memset(work,0,sizeof(work));
        while(P--)
        {
            int x;
            scanf("%d",&x);
            for(int i=x;i<=N;i+=x)
            {
                work[i]=true;
            }
        }
        int cnt=0;
        for(int i=1;i<=N;i++)
        {
            if(i%7!=6&&i%7!=0&&work[i])cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}

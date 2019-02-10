#include<stdio.h>
#include<set>
using namespace std;
int main()
{
    int n;
    int cas=0;
    while(scanf("%d",&n)==1)
    {
        int b[105];
        b[0]=0;
        bool B2=true;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
            if(b[i]<=b[i-1])B2=false;
        }
        cas++;
        printf("Case #%d: ",cas);
        if(!B2)
        {
            printf("It is not a B2-Sequence.\n\n");
            continue;
        }
        set<int> s;
        for(int i=1;i<=n&&B2;i++)
        {
            for(int j=1;j<=i&&B2;j++)
            {
                int k=b[i]+b[j];
                if(s.count(k)>0)B2=false;
                s.insert(k);
            }
        }
        if(B2)printf("It is a B2-Sequence.\n\n");
        else printf("It is not a B2-Sequence.\n\n");
    }
    return 0;
}

#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int G,L;
        scanf("%d%d",&G,&L);
        if(L%G)printf("-1\n");
        else printf("%d %d\n",G,L);
    }
    return 0;
}

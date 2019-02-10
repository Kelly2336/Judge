#include<stdio.h>
#include<cmath>
using namespace std;
int main()
{
    int x1,x2,y1,y2;
    while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2)>=4&&x1!=0)
    {
        int ans=2;
        if(x1==x2)ans--;
        if(y1==y2)ans--;
        else if(abs(x1-x2)==abs(y1-y2))ans=1;
        printf("%d\n",ans);
    }
    return 0;
}

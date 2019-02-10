#include<stdio.h>
#include<cmath>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int A,B,C;
        scanf("%d%d%d",&A,&B,&C);
        bool solve=false;
        int xx=sqrt(C)+1;
        for(int x=-xx; x<=xx&&!solve; x++)
        {
            int yy=C-x*x;
            if(yy<0)continue;
            yy=sqrt(yy)+1;
            for(int y=-yy; y<=yy && !solve; y++)
            {
                int z=A-x-y;
                if( x!=y && y!=z &&x!=z && x*y*z==B && x*x+y*y+z*z==C )
                {
                    printf("%d %d %d\n",x,y,z);
                    solve=true;
                }
            }
        }
        if(!solve)printf("No solution.\n");
    }
    return 0;
}

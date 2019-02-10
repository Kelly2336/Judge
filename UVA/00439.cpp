#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int main()
{
    char s1[5],s2[5];
    int dx[8]={1,1,-1,-1,2,2,-2,-2};
    int dy[8]={2,-2,2,-2,1,-1,1,-1};
    while(scanf("%s%s",s1,s2)!=EOF)
    {
        int xs=s1[0]-'a'+1;
        int ys=s1[1]-'0';
        int xe=s2[0]-'a'+1;
        int ye=s2[1]-'0';
        int m[10][10];
        memset(m,-1,sizeof(m));
        queue<int> qx,qy;
        qx.push(xs);
        qy.push(ys);
        m[xs][ys]=0;
        while(!qx.empty()&&m[xe][ye]==-1)
        {
            int x=qx.front();qx.pop();
            int y=qy.front();qy.pop();
            for(int k=0;k<8;k++)
            {
                int xx=dx[k]+x;
                int yy=dy[k]+y;
                if(xx<1||yy<1||xx>8||yy>8)continue;
                if(m[xx][yy]==-1)
                {
                    m[xx][yy]=m[x][y]+1;
                    qx.push(xx);
                    qy.push(yy);
                }
                if(xx==xe&&yy==ye)break;
            }
        }
        printf("To get from %s to %s takes %d knight moves.\n",s1,s2,m[xe][ye]);
    }
    return 0;
}

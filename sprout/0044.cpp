//喵喵抓老鼠
//bfs
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;

int xi[4]={0,0,1,-1};
int yi[4]={1,-1,0,0};


int main()
{
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        char s[120][120];
        int visit[120][120];
        memset(visit,0,sizeof(visit));
        int ki=0,kj=0;
        int mi=0,mj=0;
        int len;
        for(int i=0;i<n;i++)
        {
            scanf("%s",s[i]);
            if(!ki)
            {
                len=strlen(s[0]);
                for(int j=0;j<len;j++)
                {
                    if(s[i][j]=='K')
                    {
                        ki=i;kj=j;
                        break;
                    }
                }
            }
        }
        queue<int> qi,qj;
        while(!qi.empty())qi.pop();
        while(!qi.empty())qj.pop();
        visit[ki][kj]=1;
        qi.push(ki);
        qj.push(kj);
        while(!qi.empty()&&!mi)
        {
            int i=qi.front();
            qi.pop();
            int j=qj.front();
            qj.pop();
            for(int k=0;k<4;k++)
            {
                int x=i+xi[k];
                int y=j+yi[k];
                if(!visit[x][y]&&s[x][y]!='#')
                {
                    visit[x][y]=visit[i][j]+1;
                    if(s[x][y]=='@')
                    {
                        mi=x;
                        mj=y;
                        break;
                    }
                    qi.push(x);
                    qj.push(y);
                }
            }
        }
        if(mi)printf("%d\n",visit[mi][mj]-1);
        else printf("= =\"\n");
    }
    return 0;
}

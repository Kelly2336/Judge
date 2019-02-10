//庭院裡的水池
//dfs
#include<stdio.h>
#include<string.h>
#include<vector>
using namespace std;

int visit[1005][1005];
int graph[1005][1005];
int xi[4]= {0,0,1,-1};
int yi[4]= {1,-1,0,0};
vector<int> vi,vj;

void dfs(int i,int j)
{
    visit[i][j]=1;
    for(int k=0; k<4; k++)
    {
        int ii=i+xi[k];
        int jj=j+yi[k];
        if(!visit[ii][jj]&&graph[ii][jj])
            dfs(ii,jj);
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int H,W;
        scanf("%d%d",&H,&W);
        memset(graph,0,sizeof(graph));
        memset(visit,0,sizeof(visit));
        vi.clear();
        vj.clear();
        for(int i=1; i<=H; i++)
        {
            char s[1005];
            scanf("%s",s);
            for(int j=0; j<W; j++)
            {
                if(s[j]=='.')
                {
                    graph[i][j+1]=1;
                    vi.push_back(i);
                    vj.push_back(j+1);
                }
            }
        }
        int ans=0;
        int sz=vi.size();
        for(int g=0;g<sz;g++)
        {
            int i=vi[g];
            int j=vj[g];
            if(!visit[i][j])
            {
                dfs(i,j);
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

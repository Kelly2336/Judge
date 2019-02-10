//FASP
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pp;
int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        char s[30];
        int r,c;
        scanf("%s%d%d",s,&r,&c);
        int m[105][105];
        int high[105][105];
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
            {
                scanf("%d",&m[i][j]);
                high[i][j]=1;
            }
        queue<pp> q;
        bool unvisit[105][105]= {0};
        int ans=1;
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                q.push(pp(i,j));
        int dx[4]= {0,1,0,-1};
        int dy[4]= {1,0,-1,0};
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            unvisit[x][y]=true;
            q.pop();
            for(int k=0; k<4; k++)
            {
                int xx=x+dx[k];
                int yy=y+dy[k];
                if(xx>=0&&xx<r&&yy>=0&&yy<c)
                {
                    if(m[xx][yy]<m[x][y]&&high[xx][yy]<high[x][y]+1)
                    {
                        high[xx][yy]=high[x][y]+1;
                        if(unvisit[xx][yy])
                        {
                            q.push(pp(xx,yy));
                            unvisit[xx][yy]=false;
                        }
                        ans=max(ans,high[xx][yy]);
                    }
                }
            }
        }
        printf("%s: %d\n",s,ans);
    }
    return 0;
}

#include<stdio.h>
#include<queue>
#include<map>
using namespace std;

int main()
{
    int t,kase=0;
    while(scanf("%d",&t)==1&&t)
    {
        printf("Scenario #%d\n",++kase);

        map<int,int> team;
        for(int i=0;i<t;i++)
        {
            int n,x;
            scanf("%d",&n);
            while(n--)
            {
                scanf("%d",&x);
                team[x]=i; //½s¸¹
            }
        }

        queue<int> q,q2[1005];
        while(1)
        {
            int x;
            char cmd[15];
            scanf("%s",cmd);
            if(cmd[0]=='S')break;
            else if(cmd[0]=='E')
            {
                scanf("%d",&x);
                int t=team[x];
                if(q2[t].empty())q.push(t);
                q2[t].push(x);
            }
            else if(cmd[0]=='D')
            {
                int t=q.front();
                printf("%d\n",q2[t].front());
                q2[t].pop();
                if(q2[t].empty())q.pop();
            }
        }
        printf("\n");
    }
    return 0;
}

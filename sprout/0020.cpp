//中國人排隊問題
//注意自己一團的狀況
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
short int m[1000000];
int main()
{
    int n;
    int line=1;
    while(scanf("%d",&n)==1)
    {
        memset(m,0,sizeof(m));
        printf("Line #%d\n",line++);
        for(int i=1;i<=n;i++)
        {
            int t;
            scanf("%d",&t);
            while(t--)
            {
                int p;
                scanf("%d",&p);
                m[p]=i;//p為第i團
            }
        }
        queue<int> team;
        queue<int> people[1005];
        while(1)
        {
            char s[10];
            scanf("%s",s);
            if(s[0]=='E')
            {
                int p;
                scanf("%d",&p);
                int ti=m[p];
                if(people[ti].empty()||ti==0)
                {
                    team.push(ti);
                }
                people[ti].push(p);
            }
            else if(s[0]=='D')
            {
                int ti=team.front();
                printf("%d\n",people[ti].front());
                people[ti].pop();
                if(people[ti].empty()||ti==0)team.pop();
            }
            else if(s[0]=='S')break;
        }
    }
    return 0;
}

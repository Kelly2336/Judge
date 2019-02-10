#include<stdio.h>
#include<queue>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while(scanf("%d",&n)==1&&n)
    {
        printf("Discarded cards:");
        queue<int> q;
        for(int i=1; i<=n; i++)q.push(i);
        int t;
        if(n>1)
        {
            printf(" 1");
            q.pop();
            t=q.front();
            q.pop();
            q.push(t);
        }
        while(q.size()>=2)
        {
            t=q.front();
            q.pop();
            printf(", %d",t);
            t=q.front();
            q.pop();
            q.push(t);
        }
        if(n==1)t=1;
        else t=q.front();
        printf("\nRemaining card: %d\n",t);
    }
    return 0;
}

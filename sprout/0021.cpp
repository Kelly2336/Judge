//陸行鳥大賽車
//linked list
#include<stdio.h>
using namespace std;
struct car
{
    int next;
    int last;
};
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        car c[100005];
        for(int i=0; i<=n; i++)
        {
            c[i].last=i-1;
            c[i].next=i+1;
        }
        int m;
        scanf("%d",&m);
        for(int i=0; i<m; i++)
        {
            int t,x;
            scanf("%d%d",&t,&x);
            if(t)
            {
                //t==1
                int li = c[x].last;
                if(li!=0)
                {
                    c[x].last = c[li].last;
                    c[li].next = c[x].next;
                    c[x].next = li;
                    c[li].last = x;
                    c[c[x].last].next=x;
                    c[c[li].next].last=li;
                }
            }
            else
            {
                //t==0
                int ni=c[x].next;
                int li=c[x].last;
                c[li].next=ni;
                c[ni].last=li;
            }
        }
        int next_id=c[0].next;
        printf("%d",next_id);
        while(1)
        {
            next_id=c[next_id].next;
            if(next_id!=n+1)printf(" %d",next_id);
            else break;
        }
        printf("\n");
    }
    return 0;
}

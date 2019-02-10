// queue 練習
#include<stdio.h>
using namespace std;
int main()
{
    int t;
    while(scanf("%d",&t)==1)
    {
        int q[100005];
        int rear=0,front=0;
        while(t--)
        {
            int r;
            scanf("%d",&r);
            if(r==1)//push
            {
                scanf("%d",&q[rear]);
                rear++;
            }
            else//pop
            {
                if(front==rear)
                {
                    printf("empty!");
                    front=0;
                    rear=0;
                }
                else
                {
                    printf("%d",q[front]);
                    front++;
                }
                printf("\n");
            }
        }
    }
    return 0;
}

//stack 練習
#include<stdio.h>
using namespace std;
int main()
{
    int t;
    while(scanf("%d",&t)==1)
    {
        int s[100005];
        int rear=0,top=0;
        for(int i=0;i<t;i++)
        {
            int q;
            scanf("%d",&q);
            if(q==1)//push
            {
                int n;
                scanf("%d",&n);
                s[top]=n;
                top++;
            }
            else//pop
            {
                top--;
                if(top>=rear)
                {
                    printf("%d\n",s[top]);
                }
                else
                {
                    printf("empty!\n");
                    rear=0;top=0;
                }
            }
        }
    }
    return 0;
}

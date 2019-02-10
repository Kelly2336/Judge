#include<stdio.h>
#include<stack>
#include<cstring>
using namespace std;
int main()
{
    while(1)
    {
        int n;
        scanf("%d",&n);
        if(n==0)break;
        while(1)
        {
            int a[1050],b[1050];
            scanf("%d",&b[0]);
            if(b[0]==0)break;
            for(int i=1;i<n;i++)scanf("%d",&b[i]);
            memset(a,0,sizeof(int)*(n+1));
            stack<int> s;
            bool P=true;
            for(int i=0;i<n;i++)
            {
                if(a[b[i]]==0)
                {
                    for(int j=1;j<=b[i];j++)
                    {
                        if(a[j]==0)
                        {
                            s.push(j);
                            a[j]=1;
                        }
                    }
                }
                if(s.top()==b[i])
                {
                    s.pop();
                }
                else
                {
                    P=false;
                    break;
                }
            }
            if(P)printf("Yes\n");
            else printf("No\n");
        }
        printf("\n");
    }
    return 0;
}

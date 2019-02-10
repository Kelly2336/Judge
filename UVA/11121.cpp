#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
    int t;
    while(scanf("%d",&t)==1)
    {
        for(int cas=1; cas<=t; cas++)
        {
            int n;
            scanf("%d",&n);
            vector<int> ans;
            ans.clear();
            while(n!=0&&n!=1)
            {
                int r=n%-2;
                n/=-2;
                if(r==-1)
                {
                    r=1;
                    n++;
                }
                ans.push_back(r);
            }
            ans.push_back(n);
            int len=ans.size();
            printf("Case #%d: ",cas);
            for(int i=len-1; i>=0; i--)
            {
                printf("%d",ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}

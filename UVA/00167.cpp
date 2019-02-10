//¤K¬Ó¦Z
#include<stdio.h>
using namespace std;
int ans;
int p[8][8];
int a[8];
void eight(int cur)
{
    if(cur==8)
    {
        int sum=0;
        for(int i=0;i<8;i++)
        {
            int j=a[i];
            sum+=p[i][j];
        }
        if(sum>ans)ans=sum;
        return;
    }
    for(int i=0;i<8;i++)
    {
        bool ok=true;
        for(int j=0;j<cur;j++)
        {
            if(i==a[j]||(cur+i)==(j+a[j])||(cur-i)==(j-a[j]))
            {
                ok=false;
                break;
            }
        }
        if(ok)
        {
            a[cur]=i;
            eight(cur+1);
        }
    }
}
int main()
{
    int k;
    while(scanf("%d",&k)==1&&k)
    {
        while(k--)
        {
            for(int i=0;i<8;i++)
            {
                for(int j=0;j<8;j++)
                {
                    scanf("%d",&p[i][j]);
                }
            }
            ans=0;
            eight(0);
            printf("%5d\n",ans);
        }
    }
    return 0;
}

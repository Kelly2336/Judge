#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
    int t[1005];
    int ans[2005][2];
    int T,m;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&m);
        if(!m)
        {
            printf("0\n");
            continue;
        }
        for(int i=0; i<m; i++)scanf("%d",&t[i]);
        sort(t,t+m);
        int sum=0;
        //A>B>C=t[1]>D=t[0]
        m--;
        int ai=0;
        for(; m>=3; m-=2)
        {
            int t1=t[m]+t[0]+t[m-1]+t[0];
            //AD-D-BD-D
            int t2=t[1]+t[0]+t[m]+t[1];
            //CD-C-AB-D
            sum+=min(t1,t2);
            if(t1<t2)
            {
                ans[ai][0]=t[m];
                ans[ai][1]=t[0];
                ai++;
                ans[ai][0]=t[0];
                ans[ai][1]=-1;
                ai++;
                ans[ai][0]=t[m-1];
                ans[ai][1]=t[0];
                ai++;
                ans[ai][0]=t[0];
                ans[ai][1]=-1;
                ai++;
            }
            else
            {
                ans[ai][0]=t[1];
                ans[ai][1]=t[0];
                ai++;
                ans[ai][0]=t[0];
                ans[ai][1]=-1;
                ai++;
                ans[ai][0]=t[m-1];
                ans[ai][1]=t[m];
                ai++;
                ans[ai][0]=t[1];
                ans[ai][1]=-1;
                ai++;
            }
        }
        if(m==2)
        {
            sum+=t[2]+t[1]+t[0];//AD-D-CD
            ans[ai][0]=t[2];
            ans[ai][1]=t[0];
            ai++;
            ans[ai][0]=t[0];
            ans[ai][1]=-1;
            ai++;
            ans[ai][0]=t[1];
            ans[ai][1]=t[0];
            ai++;
        }
        else if(m==1)
        {
            sum+=t[1];//CD
            ans[ai][0]=t[1];
            ans[ai][1]=t[0];
            ai++;
        }
        else
        {
            sum+=t[0];//D
            ans[ai][0]=t[0];
            ans[ai][1]=-1;
            ai++;
        }
        printf("%d\n",sum);
        for(int i=0;i<ai;i++)
        {
            printf("%d",ans[i][0]);
            if(ans[i][1]!=-1)printf(" %d",ans[i][1]);
            printf("\n");
        }
        if(T)printf("\n");
    }
    return 0;
}

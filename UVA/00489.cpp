#include<stdio.h>
#include<cstring>
int main()
{
    int t;
    while(scanf("%d",&t)>0&&t!=-1)
    {
        char ans[100],guess[100];
        scanf("%s%s",ans,guess);
        int lena=strlen(ans);
        int leng=strlen(guess);
        int left=lena;
        int chance=7;
        bool win=false,lose=false;
        for(int i=0;i<leng;i++)
        {
            bool success=false;
            for(int j=0;j<lena;j++)
            {
                if(ans[j]==guess[i])
                {
                    left--;
                    ans[j]=' ';
                    success=true;
                }
            }
            if(!success)chance--;
            if(chance==0)lose=true;
            if(left==0)win=true;
            if(win||lose)break;
        }
        printf("Round %d\n",t);
        if(win)printf("You win.\n");
        else if(lose)printf("You lose.\n");
        else printf("You chickened out.\n");
    }
    return 0;
}

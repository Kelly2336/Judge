#include<stdio.h>
#include<string.h>
using namespace std;
int x[4]= {1,-1,0,0};
int y[4]= {0,0,1,-1};
char a[1500][1500];
bool v[1500][1500];
int h,w;
void dfs(int xx,int yy)
{
    for(int k=0; k<4; k++)
    {
        int xxx=xx+x[k];
        int yyy=yy+y[k];
        if(xxx<0||xxx>=h||yyy<0||yyy>=w)continue;
        if(!v[xxx][yyy]&&a[xxx][yyy]==a[xx][yy])
        {
            v[xxx][yyy]=true;
            dfs(xxx,yyy);
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int ti=1; ti<=t; ti++)
    {
        scanf("%d%d ",&h,&w);
        for(int i=0; i<h; i++)
        {
            scanf(" %s",a[i]);
        }
        memset(v,0,sizeof(v));
        int cnt[26];
        memset(cnt,0,sizeof(cnt));
        for(int i=0; i<h; i++)
        {
            for(int j=0; j<w; j++)
            {
                if(!v[i][j])
                {
                    cnt[a[i][j]-'a']++;
                    v[i][j]=true;
                    dfs(i,j);
                }
            }
        }
        printf("World #%d\n",ti);
        while(1)
        {
            int MAX=0;
            int ai=0;
            for(int i=0; i<26; i++)
            {
                if(cnt[i]>MAX)
                {
                    MAX=cnt[i];
                    ai=i;
                }
            }
            if(!MAX)break;
            printf("%c: %d\n",'a'+ai,MAX);
            cnt[ai]=-1;
        }
    }
    return 0;
}

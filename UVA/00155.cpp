#include<stdio.h>
using namespace std;
int x,y;
int dx[4]={1,1,-1,-1};
int dy[4]={1,-1,1,-1};
int cur(int mx,int my,int len)//中心點、k
{
    if(!len||mx<0||mx>2048||my<0||my>2048)return 0;
    int near=100000000;
    int id=0;
    for(int i=0;i<4;i++)//找最近的頂點去做下一層遞迴
    {
        int xx=mx+len*dx[i];
        int yy=my+len*dy[i];
        int dist=(x-xx)*(x-xx)+(y-yy)*(y-yy);
        if(dist<near){near=dist;id=i;}
    }
    int cnt=0;
    if(x<=mx+len&&x>=mx-len&&y<=my+len&&y>=my-len)cnt=1;//檢察正方形有沒有包含此點
    return cnt+cur(mx+len*dx[id],my+len*dy[id],len/2);
}
int main()
{
    int k;
    while(1)
    {
        scanf("%d%d%d",&k,&x,&y);
        if(!k&&!x&&!y)break;
        printf("%3d\n",cur(1024,1024,k));
    }
    return 0;
}

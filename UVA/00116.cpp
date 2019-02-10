#include<stdio.h>
#include<algorithm>
#include<iostream>
#define INF 2147483647
using namespace std;
int main()
{
    int a[12][120],d[12][120],next[12][120];
    int m,n;
    while(scanf("%d%d",&m,&n)==2)
    {
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        int ans=INF;
        int first=0;
        for(int j=n-1; j>=0; j--)
        {
            for(int i=0; i<m; i++)
            {
                if(j==n-1)d[i][j]=a[i][j];
                else
                {
                    int row[3]= {i,i-1,i+1};
                    if(i==0)row[1]=m-1;
                    if(i==m-1)row[2]=0;
                    sort(row,row+3);
                    d[i][j]=INF;
                    for(int k=0; k<3; k++)
                    {
                        int v=d[row[k]][j+1]+a[i][j];
                        if(v<d[i][j])
                        {
                            d[i][j]=v;
                            next[i][j]=row[k];
                        }
                    }
                }
                if(j==0 && (d[i][j]<ans||(a[i][0]<a[first][0]&&d[i][j]==ans)))
                {
                    ans=d[i][j];
                    first=i;
                }
            }
        }
        printf("%d",first+1);
        for(int i=next[first][0],j=1;j<n;i=next[i][j],j++)
        {
            printf(" %d",i+1);
        }
        cout<<endl<<ans<<endl;
        //printf("€n%d\n",ans);
    }
    return 0;
}

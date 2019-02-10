//DP
#include<stdio.h>
#include<iostream>
#include<string>
#include<string.h>
#include<sstream>
using namespace std;
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    while(scanf("%d",&t)==1)
    {
        while(t--)
        {
            int w,n;
            scanf("%d%d",&w,&n);
            char aa;scanf("%c",&aa);
            int a[100][100];
            memset(a,0,sizeof(a));
            for(int i=1;i<=w;i++)
            {
                string s;
                getline(cin,s);
                //cout<<s<<endl;
                stringstream ss;
                ss.clear();
                ss.str(s);
                ss>>i;
                int r;
                while(ss>>r)
                {
                    a[i][r]=-1;
                }
            }
            int k=1;
            for(int i=1;i<=w;i++)
            {
                if(a[i][1]!=-1)a[i][1]=k;
                else k=-1;
            }
            k=1;
            for(int i=1;i<=n;i++)
            {
                if(a[1][i]!=-1)a[1][i]=k;
                else k=-1;
            }
            for(int i=2;i<=w;i++)
            {
                for(int j=2;j<=n;j++)
                {
                    if(a[i][j]!=-1)
                    {
                        a[i][j]=0;
                        if(a[i-1][j]!=-1)
                            a[i][j]+=a[i-1][j];
                        if(a[i][j-1]!=-1)
                            a[i][j]+=a[i][j-1];
                    }
                }
            }
            if(a[w][n]==-1)a[w][n]=0;
            printf("%d\n",a[w][n]);
            if(t>=1)printf("\n");
        }
    }
    return 0;
}

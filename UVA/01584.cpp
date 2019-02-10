#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    /*freopen("1584.txt","r",stdin);
    freopen("1584out.txt","w",stdout);*/
    int n;
    scanf("%d",&n);
    for(int j=0;j<n;j++)
    {
        char a[1200],ans[1200];
        scanf("%s",a);
        //if(cin.fail())break;
        int len=strlen(a);
        strcpy(ans,a);
        for(int i=1;i<len;i++)
        {
            char r[1200];
            for(int j=0;j<len;j++)
            {
                r[j]=a[(i+j)%len];
            }
            r[len]='\0';
            if(strcmp(ans,r)>0)
            {
                strcpy(ans,r);
            }
        }
        printf("%s\n",ans);
    }
    return 0;
}

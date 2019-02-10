// 大善人老闆救濟東南亞兒童
#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int b[100050];
        for(int i=0;i<n;i++)scanf("%d",&b[i]);
        int s[100050];
        int top=0;
        int p=0;
        bool success=true;
        for(int i=0;i<n;i++)
        {
            while(b[i]>p)//push
            {
                p++;
                top++;
                s[top]=p;
            }
            if(top>0&&b[i]==s[top])//pop
            {
                top--;
            }
            else
            {
                success=false;
                break;
            }
        }
        if(success)printf("Yes");
        else printf("No");
        cout<<endl;
    }
    return 0;
}

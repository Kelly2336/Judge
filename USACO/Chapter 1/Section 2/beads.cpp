/*
ID: whitech1
TASK: beads
LANG: C++
*/
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    freopen("beads.in","r",stdin);
    freopen("beads.out","w",stdout);
    int len;
    scanf("%d",&len);
    char A[400],a[1200];
    scanf("%s",A);
    strcpy(a,A);
    strcpy(a+len,A);
    strcpy(a+len+len,A);
    int MAX=0;
    for(int t=len;t<len*2;t++)
    {
        int sum=0;
        int l=t;
        char ll=a[t];
        while(l>0)
        {
            if(a[l]==ll||a[l]=='w')
            {
                sum++;
                l--;
            }
            else if(ll=='w')
            {
                ll=a[l];
                l--;
                sum++;
            }
            else break;
        }
        int r=t+1;
        char rr=a[t+1];
        while(r<len*3)
        {
            if(a[r]==rr||a[r]=='w')
            {
                sum++;
                r++;
            }
            else if(rr=='w')
            {
                rr=a[r];
                r++;
                sum++;
            }
            else break;
        }
        if(sum>len)sum=len;
        if(sum>MAX)MAX=sum;
        if(sum>=len)break;
    }
    printf("%d",MAX);
    cout<<endl;
    return 0;
}

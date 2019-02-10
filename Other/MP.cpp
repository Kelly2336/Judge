//MP
//Morris-Pratt Algorithm
//string matching
#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
#define max_len 1000

vector<int> KMP_matching(const char *s,const int *F,const char *t)
{
    vector<int> ans;
    int p=-1;
    for(int i=0;t[i];i++)
    {
        while( p!=-1 && s[p+1]!=t[i] )
            p=F[p];
        if(s[p+1]==t[i])
            p++;
        if(!s[p+1])
        {
            ans.push_back(i-p);
            p=F[p];
        }
    }
    return ans;
}

void KMP_failure(const char *s,int F[])
{
    int p=F[0]=-1;
    for(int i=1;s[i];i++)
    {
        while( p!=-1 && s[p+1]!=s[i] )
            p=F[p];
        if(s[p+1]==s[i])
            p++;
        F[i]=p;
    }
}

int main()
{
    char s[max_len],t[max_len];
    int F[max_len];
    scanf("%s%s",s,t);
    KMP_failure(s,F);
    vector<int> ans=KMP_matching(s,F,t);
    for(vector<int>::iterator iter=ans.begin();iter!=ans.end();iter++)
        printf("%d ",*iter);
    printf("\n");
    return 0;
}

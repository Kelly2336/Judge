//weighted Longest Increasing Subsequence
//絕對遞增
#include<stdio.h>
#include<iostream>
#include<map>
using namespace std;
#define max_len 150010
int main()
{
    int len;	//length of sequence
    scanf("%d",&len);
    int s[max_len];	//sequence
    int w[max_len];	//weight
    for(int i=0; i<len; i++)scanf("%d",&s[i]);
    for(int i=0; i<len; i++)scanf("%d",&w[i]);

    map<int,int> m;
    m.erase(m.begin(),m.end());
    int ans=w[0];
    m[-1]=0;
    m[s[0]]=w[0];
    map<int,int>::iterator iter;

    for(int i=1; i<len; i++)
    {
        iter=m.lower_bound(s[i]);
        iter--;
        int ww=iter->second+w[i];
        iter++;
        if( iter!=m.end() && iter->first==s[i] )	//m[s[i]]exist
        {
            if( ww > iter->second ) iter->second=ww;
        }
        else
        {
            m.insert( iter , pair<int,int>(s[i],ww) );
            //m[s[i]]=ww;
        }
        if(ww>ans)ans=ww;

        map<int,int>::iterator iter_end=m.end();
        for( iter=m.upper_bound(s[i]) ; iter!=iter_end ; )
        {
            if(iter->second<=ww)
                iter=m.erase(iter);	//return next iterator
            else break;
        }
    }
    printf("%d\n",ans);
    return 0;
}

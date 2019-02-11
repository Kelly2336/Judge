//BFS
#include<vector>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
inline int ch(char c)
{
    return c-'A';
}
int main()
{
    ios_base::sync_with_stdio(false);
    int N,M;
    while(cin>>N>>M)
    {
        int cnt[26]= {0};
        vector<int> v[26];
        char c;
        queue<int> q;
        int year[26]= {0};
        for(int i=0; i<3; i++)
        {
            cin>>c;
            cnt[ch(c)]=3;
            q.push(ch(c));
        }
        while(M--)
        {
            char a,b;
            cin>>a>>b;
            v[ch(a)].push_back(ch(b));
            v[ch(b)].push_back(ch(a));
        }
        int ans=0;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            int sz=v[u].size();
            for(int i=0; i<sz; i++)
            {
                int uu=v[u][i];
                cnt[uu]++;
                if(cnt[uu]==3)
                {
                    q.push(uu);
                    year[uu]=year[u]+1;
                    ans=year[uu];
                }
            }
        }
        int success=0;
        for(int i=0;i<26;i++)
        {
            if(cnt[i]>=3)
            {
                success++;
            }
        }
        if(success==N)cout<<"WAKE UP IN, "<<ans<<", YEARS"<<endl;
        else cout<<"THIS BRAIN NEVER WAKES UP"<<endl;
    }
    return 0;
}

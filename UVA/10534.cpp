#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;

int LIS(vector<int>& s,vector<int>& t)
{
    if(s.size()==0)return 0;

    vector<int> v;
    v.push_back(s[0]);

    for(int i=1;i<s.size();i++)
    {
        if(s[i]>v.back())
        {
            v.push_back(s[i]);
            t[i]=v.end()-v.begin();
        }
        else
        {
            vector<int>::iterator it;
            it=lower_bound(v.begin(),v.end(),s[i]);//(*it>=s[i])
            *it=s[i];
            t[i]=(it-v.begin()+1);
        }
    }
    return v.size();
}

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        vector<int> s(n);
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
        }

        vector<int> a(s.size(),1);
        LIS(s,a);

        vector<int> rs(s.rbegin(),s.rend());
        vector<int> b(rs.size(),1);
        LIS(rs,b);

        vector<int> c(b.rbegin(),b.rend());

        int ans=0,mx=-1;
        /*for(int i=0;i<n;i++)
        {
            printf("%3d",a[i]);
        }
        printf("\n");
        for(int i=0;i<n;i++)
        {
            printf("%3d",c[i]);
        }
        printf("\n");*/
        for(int i=0;i<n;i++)
        {
            ans=2*min(a[i],c[i])-1;
            if(mx<ans)mx=ans;
        }
        printf("%d\n",mx);
    }
    return 0;
}

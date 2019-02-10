#include<stdio.h>
#include<ctype.h>
#include<vector>
#include<algorithm>
using namespace std;
int r[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,0,7,7,8,8,8,9,9,9,0};
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        vector<int> v;
        char s[80];
        for(int i=0;i<n;i++)
        {
            scanf(" %s",s);
            int num=0;
            for(int j=0;s[j];j++)
            {
                if(isalpha(s[j]))num=num*10+r[s[j]-'A'];
                else if(isdigit(s[j]))num=num*10+s[j]-'0';
            }
            v.push_back(num);
        }
        sort(v.begin(),v.end());
        v.push_back(10000000);
        int cnt=1;
        bool dul=false;
        for(int i=1;i<=n;i++)
        {
            if(v[i]==v[i-1])cnt++;
            else
            {
                if(cnt>1)
                {
                    printf("%03d-%04d %d\n",v[i-1]/10000,v[i-1]%10000,cnt);
                    cnt=1;
                    dul=true;
                }
            }
        }
        if(!dul)printf("No duplicates.\n");
        if(t)printf("\n");
    }
    return 0;
}

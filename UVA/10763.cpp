#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
int main()
{
    int n;
    while(1)
    {
        scanf("%d",&n);
        if(!n)break;
        multiset<ii> s;
        multiset<ii>::iterator iter;
        while(n--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            iter=s.find(ii(a,b));
            if(s.end()==iter)s.insert(ii(b,a));
            else s.erase(iter);
        }
        if(s.empty())printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}

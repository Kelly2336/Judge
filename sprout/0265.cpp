//欸迪的字串
//Rolling Hash
#include<stdio.h>
#include<string.h>
#include<vector>
#define LEN 500005
const int mod = 1e9+7;
const long long int c = 128;
using namespace std;
char s[LEN],s2[LEN];
long long int h[LEN];
inline long long int ch(char k)
{
    return k-'a'+20;
}
int main()
{
    scanf("%s",s);
    scanf("%s",s2);
    int len = strlen(s);
    int len2 = strlen(s2);
    long long int x = c;
    long long int a = ch(s[0]);
    for(int i=1; i<len; i++)
    {
        a = a*c+ch(s[i]);
        a %= mod;
        x = x*c%mod;
    }
    h[0] = ch(s2[0]);
    for(int i=1; i<len2; i++)
    {
        h[i] = h[i-1]*c+ch(s2[i]);
        h[i] %= mod;
    }
    vector<int> ans;
    ans.clear();
    for(int i=0; i<=len2-len; i++)
    {
        long long int k = h[i+len-1];
        if(i) k -= h[i-1]*x%mod;
        k += mod;
        k %= mod;
        if(a==k)ans.push_back(i);
    }

    int sz = ans.size();
    if(sz)
    {
        printf("%d",ans[0]);
        for(int i=1; i<sz; i++)
        {
            printf(" %d",ans[i]);
        }
    }
    printf("\n");
    return 0;
}

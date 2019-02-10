#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    char s[110];
    int a[26]={1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
    for(int t=1;t<=n;t++)
    {
        cin.getline(s,105);
        int len=strlen(s);
        int cnt=0;
        for(int i=0;i<len;i++)
        {
            if(s[i]==' ')cnt++;
            else cnt+=a[s[i]-'a'];
        }
        printf("Case #%d: %d\n",t,cnt);
    }
    return 0;
}

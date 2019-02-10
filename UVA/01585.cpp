#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char space[2];
    cin.getline(space,2);//'\0'
    for(;n>0;n--)
    {
        char s[100];
        int score[100];
        cin.getline(s,100);
        int len=strlen(s);
        if(s[0]=='O')score[0]=1;
        else score[0]=0;
        for(int i=1;i<len;i++)
        {
            if(s[i]=='O')score[i]=score[i-1]+1;
            else score[i]=0;
        }
        int ans=0;
        for(int i=0;i<len;i++)
        {
            ans+=score[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}

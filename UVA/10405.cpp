#include<iostream>
#include<cstring>
using namespace std;
int lcs[1005][1005];
int main()
{
    while(1)
    {
        char a[1005],b[1005];
        cin.getline(a+1,1004);
        if(cin.fail())break;
        cin.getline(b+1,1004);
        int la=strlen(a+1);
        int lb=strlen(b+1);
        memset(lcs,0,sizeof(lcs));
        for(int i=1;i<=la;i++)
        {
            for(int j=1;j<=lb;j++)
            {
                if(a[i]==b[j])
                {
                    lcs[i][j]=lcs[i-1][j-1]+1;
                }
                else
                {
                    if(lcs[i-1][j]>lcs[i][j-1])
                    {
                        lcs[i][j]=lcs[i-1][j];
                    }
                    else
                    {
                        lcs[i][j]=lcs[i][j-1];
                    }
                }
            }
        }
        cout<<lcs[la][lb]<<endl;
    }
    return 0;
}

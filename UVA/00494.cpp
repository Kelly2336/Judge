#include<iostream>
#include<cstring>
#include<ctype.h>
using namespace std;
int main()
{
    char s[1000];
    while(1)
    {
        cin.getline(s,1000);
        if(cin.fail())break;
        int len = strlen(s);
        int word =0;
        bool leter =false;
        for(int i=0;i<len;i++)
        {
            if(isalpha(s[i]))
            {
                if(!leter)
                {
                    word+=1;
                    leter=true;
                }
            }
            else leter=false;
        }
        cout<<word<<endl;
    }
    return 0;
}

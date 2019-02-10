//溫力的故事
//Trie
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
struct Trie
{
    Trie* c[26];
    int cnt;
    Trie(): cnt(0)
    {
        memset(c,0,sizeof(c));
    }
};
Trie* root=new Trie();

int ch(char a)
{
    return a-'a';
}

void Insert(char* s)
{
    Trie* ptr=root;
    while(*s)
    {
        if(!ptr->c[ch(*s)])
            ptr->c[ch(*s)]=new Trie();
        ptr=ptr->c[ch(*s)];
        s++;
    }
    (ptr->cnt)++;
}

int Find(char *s)
{
    Trie* ptr=root;
    while(*s)
    {
        if(!ptr->c[ch(*s)])
            return 0;
        ptr=ptr->c[ch(*s)];
        s++;
    }
    return ptr->cnt;
}

int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    char s[120];
    while(N--)
    {
        scanf("%s",s);
        Insert(s);
    }
    while(M--)
    {
        scanf("%s",s);
        printf("%d\n",Find(s));
    }
    return 0;
}

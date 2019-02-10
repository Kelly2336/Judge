//AC自動機
//string matching
//https://github.com/eecrazy/ACM/blob/master/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84/AC%E8%87%AA%E5%8A%A8%E6%9C%BA/AC%E8%87%AA%E5%8A%A8%E6%9C%BA%E6%A8%A1%E6%9D%BF.cpp
//have bug

#include<bits/stdc++.h>
#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;

struct node
{
    int cnt;
    node* next[26];
    node* fail;
    node()
    {
        cnt=0;
        fail=NULL;
        memset(next,0,sizeof(next));
    }
};
node *root;
queue<node*> q;

inline int ch(char a){return a-'a';}

void Insert(char *s)
{
    node *p=root;
    for(int i=0;s[i];i++)
    {
        int k=ch(s[i]);
        if(!(p->next[k]))
            p->next[k]=new node();
        p=p->next[k];
    }
    (p->cnt)++;
}

void build()
{
    q.push(root);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        for(int i=0;i<26;i++)
        {
            if(temp->next[i])
            {
                if(temp==root)
                {
                    (temp->next[i])->fail = root;
                }
                else
                {
                    node* p = temp->fail;
                    while(p)
                    {
                        if(p->next[i])
                        {
                            (temp->next[i])->fail = p->next[i];
                            break;
                        }
                        else p = p->fail;
                    }
                    if(!p)
                        (temp->next[i])->fail = root;
                }
                q.push(temp->next[i]);
            }
        }
    }
}

int query(char *s)
{
    int ans=0;
    node *p=root;
    for(int i=0;s[i];i++)
    {
        int k=ch(s[i]);
        while(!(p->next[k])&&p!=root)
            p = p->fail;
        if(!p)p=root;
        p = p->next[k];
        node *temp=p;
        while( temp!=root && temp->cnt!=-1 )
        {
            ans += temp->cnt;
            temp->cnt = -1;
            temp = temp->fail;
        }
    }
    return ans;
}

void del(node *nd)
{
    if(nd==NULL)return;
    for(int i=0;i<26;i++)del(nd->next[i]);
    delete(nd);
}

int main()
{
    int n;
    scanf("%d",&n);
    root = new node();
    while(n--)
    {
        char word[100];
        scanf(" %s",word);
        Insert(word);
    }
    build();
    char str[100000];
    scanf(" %s",str);
    printf("%d\n",query(str));
    del(root);
    return 0;
}

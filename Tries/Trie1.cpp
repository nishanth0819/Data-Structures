#include <iostream>
using namespace std;
struct trienode
{
    struct trienode* children[26];
    bool isendofword;
};
struct trienode* getnode()
{
    struct trienode* pnode=new trienode;
    pnode->isendofword=false;
    for(int i=0;i<26;i++)
        pnode->children[i]=NULL;
    return pnode;
}
void insert(struct trienode* root,string key)
{
    struct trienode *temp=root;
    int n=key.size();
    for(int i=0;i<n;i++)
    {
        int index=key[i]-'a';
        if(!temp->children[index])
            temp->children[index]=getnode();
        temp=temp->children[index];
    }
    temp->isendofword=true;
}
void display(struct trienode*root,char str[],int level)
{
    if(root->isendofword==true)
    {
        str[level]='\0';
        cout<<str<<endl;
    }
    for(int i=0;i<26;i++)
    {
        if(root->children[i])
        {
            str[level]=i+'a';
            display(root->children[i],str,level+1);
        }
    }
}
int main()
{
    struct trienode *root=getnode();
    insert(root,"govardhan");
    insert(root,"nishanth");
    insert(root,"govardhansai");
    char str[20];
    display(root,str,0);
    return 0;
}

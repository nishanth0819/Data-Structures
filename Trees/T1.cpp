#include <iostream>
using namespace std;
struct node
{
    struct node *left;
    int data;
    struct node *right;
}*root=NULL;
struct node * create()
{
    struct node *p;
    int x;
    cin>>x;
    if(x==-1)
      return NULL;
     p=new node;
     p->data=x;
    p->left=p->right=NULL;
    cout<<"Enter the data of left child of "<<p->data<<endl;
    p->left=create();
  cout<<"Enter the data of right child of "<<p->data<<endl;
  p->right=create();
  return p;
}
void preorder(struct node *p)
{
    if(p!=NULL)
    {
        cout<<p->data<<" ";
        preorder(p->left);
        preorder(p->right);
    }
}
int main() {
   root=create();
   preorder(root);
}

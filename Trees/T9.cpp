/*You have been given a binary tree of 'N' unique nodes and a Start node from where the tree will start to burn. Given that the Start node will always exist in the tree, your task is to print the time (in minutes) that it will take to burn the whole tree.
It is given that it takes 1 minute for the fire to travel from the burning node to its adjacent node and burn down the adjacent node.
For Example :
For the given binary tree: [1, 2, 3, -1, -1, 4, 5, -1, -1, -1, -1]
Start Node: 3

    1
   / \
  2   3
     / \
    4   5

Output: 2

Explanation :
In the zeroth minute, Node 3 will start to burn.
After one minute, Nodes (1, 4, 5) that are adjacent to 3 will burn completely.
After two minutes, the only remaining Node 2 will be burnt and there will be no nodes remaining in the binary tree. 
So, the whole tree will burn in 2 minutes.
Input Format :
The first line contains elements of the tree in the level order form. The line consists of values of nodes separated by a single space. In case a node is null, we take -1 in its place.

The second line of input contains the value of the start node.

For example, the input for the tree depicted in the above image would be :

1
2 3
4 -1 5 6
-1 7 -1 -1 -1 -1
-1 -1
Explanation :
Level 1 :
The root node of the tree is 1

Level 2 :
Left child of 1 = 2
Right child of 1 = 3

Level 3 :
Left child of 2 = 4
Right child of 2 = null (-1)
Left child of 3 = 5
Right child of 3 = 6

Level 4 :
Left child of 4 = null (-1)
Right child of 4 = 7
Left child of 5 = null (-1)
Right child of 5 = null (-1)
Left child of 6 = null (-1)
Right child of 6 = null (-1)

Level 5 :
Left child of 7 = null (-1)
Right child of 7 = null (-1)*/



//CODE:

#include<map>
int finddistance(map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> &mp,BinaryTreeNode<int>* target)
{
    queue<BinaryTreeNode<int>*> q;
    q.push(target);
    map<BinaryTreeNode<int>*,int> vis;
    vis[target]=1;
    int maxi=0;
    while(q.empty()==false)
    {
        int n=q.size();
        int fl=0;
        for(int i=0;i<n;i++)
        {
            auto node=q.front();
            q.pop();
            if(node->left!=NULL && !vis[node->left])
            {
                fl=1;
                vis[node->left]=1;
                q.push(node->left);
            }
            if(node->right!=NULL && !vis[node->right])
            {
                fl=1;
                vis[node->right]=1;
                q.push(node->right);
            }
            if(mp[node] && !vis[mp[node]])
            {
                fl=1;
                vis[mp[node]]=1;
                q.push(mp[node]);
            }
        }
        if(fl)
            maxi++;
    }
    return maxi;
}
    
BinaryTreeNode<int> * findparent(BinaryTreeNode<int> * root,int start,
                                map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> &mp)
{
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    BinaryTreeNode<int> * res;
    while(q.empty()==false)
    {
        BinaryTreeNode<int> * temp=q.front();
        q.pop();
        if(temp->data==start)
            res=temp;
        if(temp->left!=NULL)
        {
            mp[temp->left]=temp;
            q.push(temp->left);
        }
        if(temp->right!=NULL)
        {
            mp[temp->right]=temp;
            q.push(temp->right);
        }
    }
    return res;
}
int timeToBurnTree(BinaryTreeNode<int>* root, int start)
{
    map<BinaryTreeNode<int>*,BinaryTreeNode<int>*> mp;
    BinaryTreeNode<int> * target=findparent(root,start,mp);
    int mini=finddistance(mp,target);
    return mini;
}

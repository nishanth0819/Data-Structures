//https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
/*Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.

You can return the answer in any order.

 

Example 1:


Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
Example 2:

Input: root = [1], target = 1, k = 3
Output: []
 

Constraints:

The number of nodes in the tree is in the range [1, 500].
0 <= Node.val <= 500
All the values Node.val are unique.
target is the value of one of the nodes in the tree.
0 <= k <= 1000*/

//CODE:

void markparent(TreeNode * root,unordered_map<TreeNode*,TreeNode*> &parent)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(q.empty()==false)
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left)
            {
                parent[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right)
            {
                parent[curr->right]=curr;
                q.push(curr->right);
            }
        }
       
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> par;
        markparent(root,par);
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> vis;
        q.push(target);
        vis[target]=true;
        int curr_level=0;
        while(q.empty()==false)
        {
            if(curr_level==k)
                break;
            curr_level++;
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* temp=q.front();
                q.pop();
                if(temp->left!=NULL && vis[temp->left]==false)
                {
                    q.push(temp->left);
                    vis[temp->left]=true;
                }
                if(temp->right !=NULL && vis[temp->right]==false)
                {
                    q.push(temp->right);
                    vis[temp->right]=true;
                }
                if(par[temp]!=NULL && vis[par[temp]]==false)
                {
                    q.push(par[temp]);
                    vis[par[temp]]=1;
                }
            }
        }
        vector<int> res;
        while(q.empty()==false)
        {
            res.push_back(q.front()->val);
            q.pop();
        }
        return res;
    }

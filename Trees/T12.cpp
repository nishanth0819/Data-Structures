/*Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.*/


//CODE:

  bool isbst(TreeNode *root,long mini,long maxi)
    {
        if(root==NULL)
            return true;
        if(root->val<=mini || root->val>=maxi)
            return false;
        return isbst(root->left,mini,root->val)&&isbst(root->right,root->val,maxi);
    }
    bool isValidBST(TreeNode* root) {
        
        return isbst(root,LONG_MIN,LONG_MAX);
        
    }

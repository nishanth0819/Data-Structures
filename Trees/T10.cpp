/*Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

 

Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true
 

Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104*/

//CODE:
 int find(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int lh=find(root->left);
        if(lh==-1)
            return -1;
        int rh=find(root->right);
        if(rh==-1)
            return -1;
        if(abs(lh-rh)>1)
            return -1;
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        int res=find(root);
        if(res==-1)
            return false;
        else
            return true;
    }

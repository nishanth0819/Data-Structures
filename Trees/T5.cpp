/*Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes are also counted into the length calculation.

It is guaranteed that the answer will in the range of 32-bit signed integer.
Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).

Input: root = [1,3,null,5,3]
Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).

Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).

*/

//CODE:
 int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode *,unsigned long int>> q;
        q.push({root,0});
       unsigned long int maxi=0;
        while(q.empty()==false)
        {
            unsigned long int size=q.size();
            unsigned long int start,end;
            for(int i=0;i<size;i++)
            {
                TreeNode* temp=q.front().first;
                unsigned long int val=q.front().second;
                if(i==0)
                    start=val;
                if(i==size-1)
                    end=val;
                if(temp->left!=NULL)
                    q.push({temp->left,(2*val)+1});
                if(temp->right!=NULL)
                    q.push({temp->right,(2*val)+2});
                q.pop();
            }
            maxi=max(maxi,end-start+1);
        }
        return maxi;
        
    }

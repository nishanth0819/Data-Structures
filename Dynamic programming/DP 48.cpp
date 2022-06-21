/*

Given the root of a binary tree, return the size of the Maximum Independent Set (MIS) in it.

An independent set is a set of nodes in a binary tree, no two of which are adjacent, i.e., there is no edge connecting any two. The size of an independent set is the total number of nodes it contains. The maximum independent set problem is finding an independent set of the largest possible size for a given binary tree.

Input:
		   1
		 /   \
		/	  \
	   /	   \
	  2			3
	   \	   / \
		\	  /	  \
		 4	 5	   6
			/ \
		   /   \
		  7		8

Output: 5

Explanation: The Maximum Independent Set (MIS) is [1, 4, 6, 7, 8].

*/

class Solution
{
public:

	/*
		A binary tree node is defined as:

		class Node
		{
		public:
			int data;									// data field
			Node* left = nullptr, *right = nullptr;		// pointer to the left and right child

			Node() {}
			Node(int data): data(data) {}
			Node(int data, Node *left, Node *right): data(data), left(left), right(right) {}
		};
	*/

	int findMISSize(Node* root)
	{
	        if(root==NULL)
	           return 0;
	        int ex=findMISSize(root->left)+findMISSize(root->right);
	        int in=1;
	        if(root->left)
	         in=in+findMISSize(root->left->left)+findMISSize(root->left->right);
	       if(root->right)
	        in=in+findMISSize(root->right->left)+findMISSize(root->right->right);
	        return max(in,ex);
	}
};

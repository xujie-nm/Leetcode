#include <iostream>
#include <string>

using namespace std;

/**
 * Definition for a binary tree node.
 */

struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(TreeNode* root, int& res)
{
	if(root == NULL)
		return;

	if(root->left != NULL)
	{
		if(root->left->left == NULL && root->left->right == NULL)
			res += root->left->val;
		helper(root->left, res);
	}

	if(root->right != NULL)
	{
		helper(root->right, res);
	}
}

int sumOfLeftLeaves(TreeNode* root)
{
	int res = 0;
	helper(root, res);
	return res;
}

int main(int argc, char const *argv[])
{
	TreeNode n1(3);
	TreeNode n2(9);
	TreeNode n3(20);
	TreeNode n4(15);
	TreeNode n5(7);
	n1.left = &n2;
	n1.right = &n3;
	n3.left = &n4;
	n3.right = &n5;

	cout << sumOfLeftLeaves(&n1) << endl;
	return 0;
}

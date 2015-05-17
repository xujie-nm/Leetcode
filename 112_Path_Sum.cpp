#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


bool helper(TreeNode* root, int sum){
    if(root == NULL)
        return false;
    if(root->left == NULL && root->right == NULL 
    && (sum - root->val == 0))
        return true;
    return helper(root->left, sum - root->val)
        || helper(root->right, sum - root->val);
}

bool hasPathSum(TreeNode* root, int sum){
    return helper(root, sum);
}

int main(int argc, const char *argv[])
{
    TreeNode n1(5);
    TreeNode n2(4);
    TreeNode n3(8);
    TreeNode n4(11);
    TreeNode n5(13);
    TreeNode n6(4);
    TreeNode n7(7);
    TreeNode n8(2);
    TreeNode n9(1);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4; 
    n3.left = &n5;
    n3.right = &n6;
    n4.left = &n7;
    n4.right = &n8;
    n6.right = &n9;

    cout << hasPathSum(&n1, 22) << endl;
    cout << hasPathSum(&n1, 27) << endl;
    cout << hasPathSum(&n1, 26) << endl;
    cout << hasPathSum(&n1, 18) << endl;
    cout << hasPathSum(&n1, 5) << endl;
    cout << hasPathSum(&n1, 222) << endl;
    return 0;
}

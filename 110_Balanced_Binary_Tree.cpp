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

int depth(TreeNode* node){
    if(node == NULL)
        return 0;
    int left = depth(node->left);
    int right = depth(node->left);
    return 1 + (left > right ? left : right);
}

bool isBalanced(TreeNode* root){
    if(root == NULL)
        return true;
    int left = depth(root->left);
    int right = depth(root->right);
    if(left - right > 1 || right - left > 1){
        return false;
    }else
        return isBalanced(root->left) && isBalanced(root->right);
}

int main(int argc, const char *argv[])
{
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(6);
    TreeNode n7(7);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;

    cout << isBalanced(&n1) << endl;
    return 0;
}

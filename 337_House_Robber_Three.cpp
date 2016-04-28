#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};

int robHelper(TreeNode* root, int& left, int& right){
    if(root == NULL)
        return 0;

    int ll = 0, lr = 0, rl = 0, rr = 0;
    left = robHelper(root->left, ll, lr);
    right = robHelper(root->right, rl, rr);

    return max(root->val + ll + lr + rl + rr, left + right);
}

int rob(TreeNode* root){
    int left, right;
    return robHelper(root, left, right);
}

int main(int argc, const char *argv[])
{
    TreeNode n1(3);
    TreeNode n2(4);
    TreeNode n3(5);
    TreeNode n4(1);
    TreeNode n5(3);
    TreeNode n6(1);

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.right = &n6;

    cout << rob(&n1) << endl;
    return 0;
}

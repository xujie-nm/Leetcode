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

void helper(vector<string> &res, string temp, TreeNode *node){
    if(node->right == NULL && node->left == NULL){
        temp += to_string(node->val);
        res.push_back(temp);
        return;
    }
    temp += to_string(node->val) + "->";
    if(node->left != NULL)
        helper(res, temp, node->left);
    if(node->right != NULL)
        helper(res, temp, node->right);
}

vector<string> binaryTreePaths(TreeNode* root){
    vector<string> res;
    if(root == NULL)
        return res;
    string temp;
    helper(res, temp, root);
    return res;
}

int main(int argc, const char *argv[])
{
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n5(5);
    n1.left = &n2;
    n1.right = &n3;
    n2.right = &n5;

    vector<string> res;
    res = binaryTreePaths(&n1);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;;
    }
    return 0;
}

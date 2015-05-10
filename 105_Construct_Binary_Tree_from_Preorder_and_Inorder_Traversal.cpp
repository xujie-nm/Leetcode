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

TreeNode* helper(vector<int> &preorder, vector<int> &inorder, pair<int, int> pre, pair<int, int> in){
    if(pre.first < 0 || pre.first > preorder.size() || pre.second > preorder.size() || pre.second < 0
       ||in.first < 0 || in.first > inorder.size() || in.second > inorder.size() || pre.second < 0
       || pre.first >= pre.second || in.first >= in.second)
        return NULL;
    TreeNode* node = new TreeNode(preorder[pre.first]);
    if(pre.first - pre.second == -1 || in.first - in.second == -1)
        return node;
    int divide = -1;
    for (int i = in.first; i < in.second; i++) {
        if(inorder[i] == preorder[pre.first]){
            divide = i;
            break;
        }
    }

    if(divide != -1){
        node->left = helper(preorder, inorder,
                       make_pair(pre.first +1, pre.first + divide - in.first + 1), make_pair(in.first, divide));
        node->right = helper(preorder, inorder,
                        make_pair(pre.first + divide - in.first +1, pre.second), make_pair(divide+1, in.second));
    }
    return node;
}

TreeNode* buildTree(vector<int> &preorder, vector<int> &inorder){
    pair<int, int> pre;
    pre.first = 0;
    pre.second = preorder.size();
    pair<int, int> in;
    in.first = 0;
    in.second = inorder.size();
    return helper(preorder, inorder, pre, in);
}

void preOrder(TreeNode *root){
    if(root == NULL)
        return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(TreeNode *root){
    if(root == NULL)
        return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

int main(int argc, const char *argv[])
{
    vector<int> preorder;    
    vector<int> inorder;    
    preorder.push_back(-1);
    //preorder.push_back(2);
    //preorder.push_back(3);
    //inorder.push_back(3);
    //inorder.push_back(2);
    inorder.push_back(-1);


    TreeNode *root;
    root = buildTree(preorder, inorder);
    preOrder(root);
    cout << endl;
    inOrder(root);
    return 0;
}

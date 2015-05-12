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

TreeNode* helper(vector<int> &inorder, vector<int> &postorder, int start, int end){
    int postIndex = postorder.size() - 1;
    if(start >= end || postorder.empty())
        return NULL;
    
    TreeNode* node = new TreeNode(postorder[postIndex]);

    int inIndex = start;
    for (; inIndex < end; inIndex++) {
        if(inorder[inIndex] == postorder[postIndex])
            break;
    }

    postorder.pop_back();
    node->right = helper(inorder, postorder, inIndex + 1, end);//先把右边的pop出去
    node->left = helper(inorder, postorder, start, inIndex);
    
    return node;
}

TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder){
    return helper(inorder, postorder, 0, inorder.size());
}

void postOrder(TreeNode *root){
    if(root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
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
    vector<int> postorder;    
    vector<int> inorder;    
    postorder.push_back(9);
    postorder.push_back(15);
    postorder.push_back(4);
    postorder.push_back(20);
    postorder.push_back(3);
    inorder.push_back(9);
    inorder.push_back(3);
    inorder.push_back(15);
    inorder.push_back(20);
    inorder.push_back(4);


    TreeNode *root;
    root = buildTree(inorder, postorder);
    postOrder(root);
    cout << endl;
    inOrder(root);
    return 0;
}

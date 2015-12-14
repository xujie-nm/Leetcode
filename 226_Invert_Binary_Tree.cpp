#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* invertTree(TreeNode* root){
    if(root == NULL)
        return root;
    TreeNode* temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);
    return root;
}

TreeNode* invertTree2(TreeNode *root){
    if(root == NULL)
        return root;
    stack<TreeNode*> Stack;
    Stack.push(root);
    while(!Stack.empty()){
        TreeNode* temp = Stack.top();
        Stack.pop();
        // 依次遍历节点
        // 并交换其左右子树
        TreeNode* swap = temp->left;
        temp->left = temp->right;
        temp->right = swap;
        if(temp->left != NULL)
            Stack.push(temp->left);
        if(temp->right != NULL)
            Stack.push(temp->right);
    }
    return root;
}

void inOrder(TreeNode*root){
    if(root->left != NULL)
        inOrder(root->left);
    cout << root->val << " ";
    if(root->right != NULL)
        inOrder(root->right);
}
void preOrder(TreeNode*root){
    cout << root->val << " ";
    if(root->left != NULL)
        preOrder(root->left);
    if(root->right != NULL)
        preOrder(root->right);
}

int main(int argc, const char *argv[])
{
    TreeNode t1(4);
    TreeNode t2(2);
    TreeNode t3(7);
    TreeNode t4(1);
    TreeNode t5(3);
    TreeNode t6(6);
    TreeNode t7(9);
    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;
    t2.right = &t5;
    t3.left = &t6;
    t3.right = &t7;

    inOrder(&t1);
    cout << endl;
    preOrder(&t1);
    cout << endl;
    
    TreeNode* root = invertTree(&t1);
    inOrder(root);
    cout << endl;
    preOrder(root);
    cout << endl;

    return 0;
}

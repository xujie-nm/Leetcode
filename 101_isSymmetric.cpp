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

bool helper(TreeNode *p, TreeNode *q){
    if(p == NULL && q == NULL)
        return true;
    
    if(p != NULL && q != NULL){
        if(p->val == q->val)
            return helper(p->left, q->right) && helper(p->right, q->left);
        else
            return false;
    }else
        return false;
}

bool isSymmetric(TreeNode* root){
    if(root == NULL)
        return true;
    return helper(root->left, root->right);
}

int main(int argc, const char *argv[])
{
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(2);
    TreeNode n4(3);
    TreeNode n5(2);
    TreeNode n6(4);
    TreeNode n7(3);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;

    cout << isSymmetric(&n1) << endl;
    return 0;
}

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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    int Max = max(p->val, q->val);
    int Min = min(p->val, q->val);
    if(root == NULL)
        return NULL;
    else if(root->val == p->val || root->val == q->val)
        return root;
    else if(root->val > Max)
        return lowestCommonAncestor(root->left, p, q);
    else if(root->val < Min)
        return lowestCommonAncestor(root->right, p, q);
    else if(root->val > Min && root->val < Max)
        return root;
}

int main(int argc, const char *argv[])
{
    TreeNode n6(6);
    TreeNode n2(2);
    TreeNode n8(8);
    TreeNode n0(0);
    TreeNode n4(4);
    TreeNode n7(7);
    TreeNode n9(9);
    TreeNode n3(3);
    TreeNode n5(5);
    n6.left = &n2;
    n6.right = &n8;
    n2.left = &n0;
    n2.right = &n4;
    n8.left = &n7;
    n8.right = &n9;
    n4.left = &n3;
    n4.right = &n5;

    TreeNode *res;
    res = lowestCommonAncestor(&n6, &n3, &n5);
    cout << "The ancestor is: " << res->val << endl;
    return 0;
}

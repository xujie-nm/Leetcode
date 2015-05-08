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

bool isSameTree(TreeNode* p, TreeNode* q){
    if(p == NULL && q == NULL)
        return true;

    if(p != NULL && q != NULL){
        if(p->val == q->val){
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }else
            return false;
    }else
        return false;
}

int main(int argc, const char *argv[])
{
    TreeNode n11(0);
    TreeNode n12(5);
    TreeNode n21(0);
    TreeNode n22(8);
    n11.left = &n12;
    n21.left = &n22;
    cout << isSameTree(&n11, &n21) << endl;
    return 0;
}

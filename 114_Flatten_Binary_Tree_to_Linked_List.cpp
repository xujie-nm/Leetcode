#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preOrder(vector<TreeNode*> &v, TreeNode* root){
    if(root == NULL)
        return;
    v.push_back(root);
    preOrder(v, root->left);
    preOrder(v, root->right);
}

void flatten(TreeNode* root){
    vector<TreeNode*> v;
    preOrder(v, root);

    for (int i = 0; i < v.size()-1; ++i)
    {
        v[i]->right = v[i+1];
        v[i]->left = NULL;
    }
}

int main(){
    TreeNode n1(0);
    flatten(&n1);
    return 0;
}

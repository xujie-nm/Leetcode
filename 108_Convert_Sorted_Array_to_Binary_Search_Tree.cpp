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

TreeNode* helper(vector<int> &num, int low, int high){
    if(low > high)
        return NULL;

    int mid = (low + high)/2;
    TreeNode* node = new TreeNode(num[mid]);

    node->left = helper(num, low, mid-1);
    node->right = helper(num, mid+1, high);

    return node;
}

TreeNode* sortedArrayToBST(vector<int> &num){
    if(num.empty())
        return NULL;

    return helper(num, 0, num.size() - 1);
}

void inOrder(TreeNode* root){
    if(root == NULL)
        return;

    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

int main(int argc, const char *argv[])
{
    vector<int> num;
    num.push_back(1);
    num.push_back(2);
    num.push_back(3);
    num.push_back(4);
    num.push_back(5);
    num.push_back(6);

    TreeNode* root;
    root = sortedArrayToBST(num);
    inOrder(root);
    cout << endl;
    return 0;
}

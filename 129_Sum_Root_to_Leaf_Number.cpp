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

void helper(TreeNode *root, vector<int> &temp, int curSum){
    curSum *= 10;
    curSum += root->val;
    if(root->left == NULL && root->right == NULL){
        temp.push_back(curSum);
        return;
    }
    if(root->left != NULL)
        helper(root->left, temp, curSum);
    if(root->right != NULL)
        helper(root->right, temp, curSum);
}

int sumNumbers(TreeNode *root){
    if(root == NULL)
        return 0;
    vector<int> temp;
    int curSum = 0;
    helper(root, temp, curSum);
    
    int sum = 0;
    if(temp.size() > 0){
        for (int i = 0; i < temp.size(); i++) {
            sum += temp[i];
        }
    }
    return sum;
}

int main(int argc, const char *argv[])
{
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    n1.left = &n2;
    n1.right = &n3;

    cout << sumNumbers(&n1) << endl;
    return 0;
}

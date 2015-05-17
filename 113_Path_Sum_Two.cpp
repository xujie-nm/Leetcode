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


void helper(TreeNode* root, int sum, vector<vector<int> > &res, vector<int> &temp){
    if(root == NULL)
        return ;
    if(root->left == NULL && root->right == NULL 
    && (sum - root->val == 0)){
        res.push_back(temp);
        return ;
    }
   
    if(root->left != NULL){
        vector<int> temp_left(temp.begin(), temp.end());
        temp_left.push_back(root->left->val);
        helper(root->left, sum - root->val, res, temp_left);
    }
    if(root->right != NULL){
        vector<int> temp_right(temp.begin(), temp.end());
        temp_right.push_back(root->right->val);
        helper(root->right, sum - root->val, res, temp_right);
    }
}

vector<vector<int> > pathSum(TreeNode* root, int sum){
    vector<vector<int> > res;
    if(root == NULL)
        return res;
    vector<int> temp;
    temp.push_back(root->val);
    helper(root, sum, res, temp);
    return res;
}

int main(int argc, const char *argv[])
{
    TreeNode n1(5);
    TreeNode n2(4);
    TreeNode n3(8);
    TreeNode n4(11);
    TreeNode n5(13);
    TreeNode n6(4);
    TreeNode n7(7);
    TreeNode n8(2);
    TreeNode n9(1);
    TreeNode n10(5);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4; 
    n3.left = &n5;
    n3.right = &n6;
    n4.left = &n7;
    n4.right = &n8;
    n6.right = &n9;
    n6.left = &n10;

    vector<vector<int> > res;
    res = pathSum(&n1, 22);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}

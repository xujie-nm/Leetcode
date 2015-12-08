#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> rightSideView(TreeNode *root){
    vector<int> res;
    if(root == NULL)
        return res;

    queue<TreeNode*> q;
    TreeNode* flag = new TreeNode(0);
    TreeNode* pre = root;
    q.push(root);
    q.push(flag);
    while(!q.empty()){
        TreeNode* temp = q.front();
        q.pop();
        if(temp == flag){
            res.push_back(pre->val);
            if(q.size() == 0)
                break;
            q.push(flag);
        }else{
            if(temp->left != NULL)
                q.push(temp->left);
            if(temp->right != NULL)
                q.push(temp->right);
            pre = temp;
        }
    }

    return res;
}

// new method, recursive
int treeHeight(TreeNode* root){
    if(root != NULL){
        return 1 + max(treeHeight(root->left), treeHeight(root->right));
    }else
        return 0;
}

void helper(TreeNode* root, vector<int>& res, int height, int Height){
    if(root != NULL){
        if(res[height] == INT_MIN)
            res[height] = root->val;
        if(height == Height-1)
            return;
        helper(root->right, res, height+1, Height);
        helper(root->left, res, height+1, Height);
    }
}

vector<int> rightSideView2(TreeNode* root){
    int height = treeHeight(root);
    vector<int> res(height, INT_MIN);
    if(res.size() == 0)
        return res;

    helper(root, res, 0, height);
    return res;
}

int main(int argc, const char *argv[])
{
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(6);
    n1.left = &n2;
    n1.right = &n3;
    n2.right = &n5;
    n3.right = &n4;
    n5.right = & n6;

    vector<int> res;
    res = rightSideView2(&n1);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    };
    cout << endl;

    return 0;
}

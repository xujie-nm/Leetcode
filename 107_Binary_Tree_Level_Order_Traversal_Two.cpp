#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > levelOrder(TreeNode* root){
    vector<vector<int> > res;
    stack<vector<int> > res_temp;

    if(root == NULL)
        return res;
    queue<TreeNode*> level;
    level.push(root);
    int levelNumber = 1;
    while(!level.empty()){
        vector<int> temp;
        for (int i = 0; i < levelNumber; i++) {
            TreeNode* node = level.front();
            level.pop();
            temp.push_back(node->val);
            if(node->left != NULL)
                level.push(node->left);
            if(node->right != NULL)
                level.push(node->right);
        }
        res_temp.push(temp);
        levelNumber = level.size();
    }
    while(!res_temp.empty()){
        res.push_back(res_temp.top());
        res_temp.pop();
    }

    return res;
}

int main(int argc, const char *argv[])
{
    TreeNode n1(3);
    TreeNode n2(9);
    TreeNode n3(20);
    TreeNode n6(15);
    TreeNode n7(7);
    n1.left = &n2;
    n1.right = &n3;
    n3.left = &n6;
    n3.right = &n7;

    vector<vector<int> > res;
    res = levelOrder(&n1);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

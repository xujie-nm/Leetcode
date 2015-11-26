#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> preorderTraversal(TreeNode *root){
    vector<int> res;
    if(root == NULL)
        return res;
    stack<TreeNode*> temp;
    temp.push(root);
    while(!temp.empty()){
        TreeNode * p = temp.top();
        temp.pop();
        res.push_back(p->val);
        // 栈，先入右，在入左
        if(p->right != NULL)
            temp.push(p->right);
        if(p->left != NULL)
            temp.push(p->left);
    }

    return res;
}

int main(int argc, const char *argv[])
{
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    n1.right = &n2;
    n2.left = &n3;

    vector<int> res;
    res = preorderTraversal(&n1);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}

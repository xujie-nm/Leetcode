#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> inorderTraversal(TreeNode *root){
    stack<TreeNode*> nodeStack;
    vector<int> res;
    while(root != NULL || !nodeStack.empty()){
        if(root != NULL){
            nodeStack.push(root);
            root = root->left;
        }else{
            if(!nodeStack.empty()){
                TreeNode* temp = nodeStack.top();
                nodeStack.pop();
                res.push_back(temp->val);
                if(temp->right != NULL)
                    root = temp->right;
            }else{
                if(root != NULL)
                    res.push_back(root->val);
                if(root->right != NULL)
                    root = root->right;
            }
        }
    }

    return res;
}

int main(int argc, const char *argv[])
{
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    n1.left = &n2;
    n1.right = &n3;
    n3.left = &n4;
    n4.right = &n5;

    vector<int> res;
    res = inorderTraversal(&n1);

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    
    
    return 0;
}

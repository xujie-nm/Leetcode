#include <algorithm>
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
//left->right->root are reverse of root->right->left
vector<int> postorderTraversal(TreeNode *root){
    vector<int> res;
    if(root == NULL)
        return res;
    stack<TreeNode*> temp;
    temp.push(root);
    while(!temp.empty()){
        TreeNode * p = temp.top();
        temp.pop();
        res.push_back(p->val);
        if(p->left != NULL)
            temp.push(p->left);
        if(p->right != NULL)
            temp.push(p->right);
    }
    
    reverse(res.begin(), res.end());
    return res;
}

// 第二个其实还是第一个的变形
vector<int> postorderTraversal1(TreeNode* root){
    vector<int> res;
    if(!root)
        return res;

    stack<TreeNode*> temp;
    temp.push(root);

    TreeNode* tempNode = NULL;
    while(!temp.empty()){
        tempNode = temp.top();
        temp.pop();
        res.insert(res.begin(), tempNode->val);
        if(tempNode->left)
            temp.push(tempNode->left);
        if(tempNode->right)
            temp.push(tempNode->right);
    }
    return res;
}

vector<int> postorderTraversal2(TreeNode *root){
    vector<int> res;
    stack<pair<TreeNode*, bool> > temp;
    //recoder nodes
    
    temp.push(make_pair(root, true));
    while(!temp.empty()){
        pair<TreeNode*, bool> p = temp.top();
        temp.pop();
        TreeNode* cur = p.first;
        if(cur == NULL)
            continue;
        // LRN
        if(p.second){
            temp.push(make_pair(cur, false));
            temp.push(make_pair(cur->right, true));
            temp.push(make_pair(cur->left, true));
        }else{
            res.push_back(cur->val);
        }
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
    res = postorderTraversal1(&n1);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}

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

void inOrder(TreeNode* root){
    if(root == NULL)
        return;
    inOrder(root->left);
    cout << root->val << endl;
    inOrder(root->right);
}

void recoverTree(TreeNode* root){
    stack<TreeNode*> nodeStack;
    vector<TreeNode*> res;
    TreeNode* cur = NULL;
    TreeNode* pre = NULL;

    while(root != NULL || !nodeStack.empty()){
        if(root != NULL){
            nodeStack.push(root);
            root = root->left;
        }else{
            if(!nodeStack.empty()){
                TreeNode* temp = nodeStack.top();
                nodeStack.pop();
                res.push_back(temp);
                if(temp->right != NULL)
                    root = temp->right;
            }else{
                if(root != NULL){
                    res.push_back(root);
                }
                if(root->right != NULL)
                    root = root->right;
            }
        }
    } 

    int s = 0;
    for (int i = 0; i < res.size()-1; i++) {
        if(res[i]->val > res[i+1]->val){
            pre = res[i];
            s = i;
            cout << "i: " << i << endl;
            break;
        }
    }

    for (int i = s+1; i < res.size()-1; i++) { 
        if(res[i]->val > res[i+1]->val){
            cur = res[i+1];
            break;
        }
    }
    
    if(cur == NULL)
        cur = res[s+1];
    int temp = pre->val;
    pre->val = cur->val;
    cur->val = temp;
}

int main(int argc, const char *argv[])
{
    TreeNode t1(2);
    TreeNode t2(3);
    TreeNode t3(1);
    TreeNode t4(4);
    TreeNode t5(5);
    t1.left = &t2;
    t1.right = &t3;
    //t3.right = &t4;
    //t4.right = &t5;

    inOrder(&t1);
    cout << "ok" << endl;
    recoverTree(&t1);
    cout << "ok" << endl;

    inOrder(&t1);
    return 0;
}

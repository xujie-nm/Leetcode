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

// faster recusive
typedef TreeNode* TreeNodePtr;

void dfs(TreeNodePtr root, 
         TreeNodePtr& pre, 
         TreeNodePtr& first, 
         TreeNodePtr& second){
    if(root == NULL)
        return;

    dfs(root->left, pre, first, second);

    // 访问root节点
    if(pre != NULL && pre->val > root->val){
        if(first == NULL){
            // 遇到第一个被调换的元素
            first = pre;
            // 如果两个被调换的元素相邻，这样正好
            second = root;
        }else{
            // 遇到第二个被调换的元素，此时不相邻
            second = root;
        }
    }

    pre = root;

    dfs(root->right, pre, first, second);
}

void recoverTree2(TreeNodePtr root){
    if(root == NULL)
        return ;

    TreeNodePtr pre = NULL;// 前一个访问的节点
    TreeNodePtr first = NULL; // 交换元素的第一个
    TreeNodePtr second = NULL; // 交换元素的第二个

    dfs(root, pre, first, second);

    // 交换第一节点和第二节点
    int temp = first->val;
    first->val = second->val;
    second->val = temp;
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
    t3.right = &t4;
    t4.right = &t5;

    inOrder(&t1);
    cout << "ok" << endl;
    recoverTree2(&t1);
    cout << "ok" << endl;

    inOrder(&t1);
    return 0;
}

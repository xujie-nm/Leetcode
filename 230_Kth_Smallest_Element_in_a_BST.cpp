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

void inOrder(TreeNode* root, vector<int> &order){
    if(root == NULL)
        return;
    if(root->left != NULL)
        inOrder(root->left, order);
    order.push_back(root->val);
    if(root->right != NULL)
        inOrder(root->right, order);
}

int kthSmallest(TreeNode* root, int k){
    if(root == NULL)
        return -1;
    vector<int> order;
    inOrder(root, order);
    return order[k-1];
}

//second solution: based on inorder

int kthSmallest2(TreeNode* root, int &k){
    if(root == NULL)
        return -1;
    int res = kthSmallest2(root->left, k);
    if(k == 0)
        return res;
    if(--k == 0)
        return root->val;
    return kthSmallest2(root->right, k);
}

int main(int argc, const char *argv[])
{
    TreeNode t1(5);
    TreeNode t2(3);
    TreeNode t3(7);
    TreeNode t4(2);
    TreeNode t5(4);
    TreeNode t6(6);
    TreeNode t7(8);
    TreeNode t8(1);
    t1.left = &t2;
    t1.right = &t3;
    t2.left = &t4;
    t2.right = &t5;
    t3.left = &t6;
    t3.right = &t7;
    t4.left = &t8;

    int k;
    while(cin >> k){
        cout << k << "th element is: "<< kthSmallest2(&t1, k) << endl;
    }
    return 0;
}

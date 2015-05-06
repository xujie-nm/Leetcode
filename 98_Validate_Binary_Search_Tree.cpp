#include <iostream>
#include <string>
#include <vector>

#define MIN -2147483649
#define MAX 2147483649
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

bool helper(TreeNode* root, int min, int max){
    if(root == NULL)
        return true;
    if(root->val <= min || root->val >= max)
        return false;
    if(!helper(root->left, min, root->val) || !helper(root->right, root->val, max))
        return false;
    return true;
}

bool isValidBST(TreeNode* root){
    long long int min = MIN;
    long long int max = MAX;
    
    return helper(root, min, max);
}

int main(int argc, const char *argv[])
{
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode t4(4);
    TreeNode t5(5);
    t1.left = &t2;
    t1.right = &t3;
    t3.right = &t4;
    t4.right = &t5;

    cout << isValidBST(&t1) << endl;
    return 0;
}

#include <algorithm>
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

#define INT_MIN -32627;

int helper(TreeNode* node, int &res){
    if(node == NULL)
        return 0;
    int l = helper(node->left, res);//取得左子树的最大路径
    int r = helper(node->right, res);//取得右子树的最大路径值
    int temp = node->val;
    temp = max(temp, temp + l);//选择当前加上左子树的较大者
    temp = max(temp, temp + r);//再选择当前加上右子树的较大者
    //这事有四种情况
    //1,有可能只有当前点的val
    //2,有可能是左子树加上当前点
    //3,有可能是右子树加上当前点
    //4,有可能是左右子树加上当前点
    res = max(res, temp);//计算当前的结果
    return max(node->val, node->val + max(l, r));//返回当前子树的最大路径和
}

int maxPathSum(TreeNode* root){
    int res = INT_MIN;
    helper(root, res);
    return res;
}

int main(int argc, const char *argv[])
{
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    t1.left = &t2;
    t1.right = &t3;

    cout << maxPathSum(&t1) << endl;
    return 0;
}

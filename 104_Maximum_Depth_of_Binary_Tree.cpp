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

int maxDepth(TreeNode* root){
    if(root == NULL)
        return 0;
    else{
        int left = 1 + maxDepth(root->left);
        int right = 1 + maxDepth(root->right);
        return left >= right ? left : right;
    }
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

    cout << maxDepth(&n1) << endl;

    return 0;
}

    /** 
    *   
    * ━━━━━━神兽出没━━━━━━
    * 　　 ┏┓　    ┏┓  
    * 　　 ┛┻━━━┛┻┓
    * 　　┃　　　　     ┃   
    * 　　┃　　 ━　    ┃   
    * 　　┃　┳┛　┗┳ ┃
    * 　　┃　　　　　   ┃ 
    * 　　┃　　 ┻　    ┃   
    * 　　┃　　　　　   ┃ 
    * 　　┗━┓　　　┏ ┛Code is far away from bug with the animal protecting
    * 　　　  ┃　　　┃ 神兽保佑,代码无bug 
    * 　　　  ┃　　　┃ 
    * 　　　  ┃　　　┗━━━┓
    * 　　　  ┃　　　　　    ┣┓
    * 　　　  ┃　　　　　    ┏┛
    * 　　　  ┗┓┓┏━┳┓┏┛
    * 　　　    ┃┫┫  ┃┫┫ 
    * 　　　    ┗┻┛  ┗┻┛ 
    *   
    */


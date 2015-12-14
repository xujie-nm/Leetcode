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

int leftDep(TreeNode* root){
    int depth = -1;
    while(root != NULL){
        depth++;
        root = root->left;
    }
    return depth;
}

int countNodes(TreeNode* root){
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;

    int depth = 1;
    int leaves = 0;
    int leftDepth, rightDepth;
    //计算叶子节点的个数和树的深度
    while(true){
        if(root->right == NULL){
            leaves++;
            break;
        }
        
        leftDepth = leftDep(root->left);
        rightDepth = leftDep(root->right);
        //保存这个树的深度
        depth = max(depth, leftDepth+1);
        //如果这个树的左子树的深度与右子树的坐深度相同
        //则左子树是满的，计算已知的叶子节点，并跳到右子树
        //否则还在左子树
        if(leftDepth == rightDepth){
            leaves += 1<<leftDepth;
            root = root->right;
        }else{
            root = root->left;
        }
    }
    return (1<<depth)-1 + leaves;
}

int countNodes2(TreeNode* root){
    if(root == NULL)
        return 0;
    int leftDepth = 0, rightDepth = 0;
    //计算左深度
    for(TreeNode* p = root; p != NULL; p = p->left)
        leftDepth++;
    //计算右深度
    for(TreeNode* p = root; p != NULL; p = p->right)
        rightDepth++;
    //如果深度相同说明树是满的，返回个数
    //如果深度不同说明树不满，递归求个数
    if(leftDepth == rightDepth)
        return (1<<leftDepth) - 1;
    else
        return 1 + countNodes2(root->left) + countNodes2(root->right);
}

// 计算一般树的节点的个数
// 在这个问题中超时
int countNodes3(TreeNode* root){
    if(root != NULL){
        return 1 + countNodes3(root->left) + countNodes3(root->right);
    }else{
        return 0;
    }
}

int main(int argc, const char *argv[])
{
    TreeNode n1(1);
    TreeNode n2(2);
    TreeNode n3(3);
    TreeNode n4(4);
    TreeNode n5(5);
    TreeNode n6(6);
    TreeNode n7(7);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;
    cout << countNodes(&n1) << endl;
    cout << countNodes2(&n1) << endl;
    cout << countNodes3(&n1) << endl;
    return 0;
}

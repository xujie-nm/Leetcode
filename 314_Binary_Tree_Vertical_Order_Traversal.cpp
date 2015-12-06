#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL){}
};

void helper(TreeNode* root, map<int, vector<TreeNode*> > &hash, int height){
    if(root != NULL){
        hash[height].push_back(root);

        helper(root->left, hash, height-1);
        helper(root->right, hash, height+1);
    }
}

// 二叉树的垂直序遍历
// 想法：
// 定义一个水平距离的概念，根节点的水平距离为0，
// 左孩子的水平距离是父亲的水平距离减一，右孩子加一
// 最后结果是一个二维数组
// 同一行的代表水平距离相同的节点
// 列从上到下代表水平距离一次增大
vector<vector<int> > BinaryTreeVerticalOrderTraversal(TreeNode* root){
    vector<vector<int> > res;
    if(root == NULL)
        return res;
     map<int, vector<TreeNode*> > hash;
     helper(root, hash, 0);
     
     for(auto it = hash.begin(); 
         it != hash.end(); 
         ++it){
         vector<int> temp;
         for (auto itVec = (it->second).begin();
              itVec != (it->second).end(); 
              itVec++) {
             temp.push_back((*itVec)->val);
         }
         res.push_back(temp);
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
    TreeNode n6(6);
    TreeNode n7(7);
    TreeNode n8(8);
    TreeNode n9(9);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;
    n6.right = &n8;
    n7.right = &n9;

    vector<vector<int> > res;
    res = BinaryTreeVerticalOrderTraversal(&n1);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

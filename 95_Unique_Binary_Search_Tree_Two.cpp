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

vector<TreeNode*> helper(int low, int high);

vector<TreeNode*> generateTrees(int n){
    vector<TreeNode*> res;
    res = helper(1, n);
    return res;
}

vector<TreeNode*> helper(int low, int high){
    vector<TreeNode*> res;
    if(low > high || low <= 0 || high <= 0){//如果不滿足這些條件退出
        res.push_back(NULL);
        return res;
    }

    if(low == high){//如果當前只有一個節點直接入數組
        TreeNode* node = new TreeNode(low);
        res.push_back(node);
        return res;
    }

    for (int i = low; i <= high; i++) {
        vector<TreeNode*> resLeft = helper(low, i-1);//收集所有可能的左子樹
        vector<TreeNode*> resRight = helper(i+1, high);//收集所有可能的右子樹
        for (int l = 0; l < resLeft.size(); l++) {//依次替換
            for (int r = 0; r < resRight.size(); r++) {
                TreeNode *root = new TreeNode(i);
                root->left = resLeft[l];
                root->right = resRight[r];
                res.push_back(root);
            }
        }
    }
    return res;
}

void outTree(TreeNode *root){
    if(root == NULL){
        cout << "# ";
        return;
    }
    cout << root->val << " ";
    outTree(root->left);
    outTree(root->right);
}

int main(int argc, const char *argv[])
{
    vector<TreeNode*> res;
    res = generateTrees(3);
    for (int i = 0; i < res.size(); i++) {
        outTree(res[i]);
        cout << endl;
    }
    
    
    return 0;
}

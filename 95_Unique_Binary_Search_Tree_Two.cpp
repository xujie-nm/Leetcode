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

// recursive
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

// dp
vector<TreeNode*> generateTrees(int n){
    vector<TreeNode*> tmp;
    vector<TreeNode*> ret;
    tmp.push_back(NULL);
    ret.push_back(new TreeNode(1));
    if(!n) 
        return tmp;

    // 每次都插入最大值到先前构造好的树中
    for (int i = 2; i <= n; i++) {
        tmp.clear();
        for (int j = 0; j < ret.size(); j++) {
            // 首先先把这个最大值放到根节点
            TreeNode *orgTree = ret[j];
            TreeNode *newNode = new TreeNode(i);
            newNode->left = copy(orgTree);
            tmp.push_back(newNode);

            // 然后再其他地方选择插入这个最大的值 
            TreeNode *orgRunner = orgTree;
            while(orgRunner){
                newNode = new TreeNode(i);
                newNode->left = orgRunner->right;
                orgRunner->right = newNode;
                tmp.push_back(copy(orgTree));

                // 删除刚才插入的值
                orgRunner->right = orgRunner->right->left;

                // 下一步
                orgRunner = orgRunner->right;
            }
        }
        ret = tmp;
    }
    return ret;
}

TreeNode* copy(TreeNode *root){
    TreeNode *ret = NULL;
    if(root){
        ret = new TreeNode(root->val);
        ret->left = copy(root->left);
        ret->right = copy(root->right);
    }
    return ret;
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

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<vector<int> > zigzagLevelOrder(TreeNode *root){
    vector<vector<int> > res;
    if(root == NULL)
        return res;
    int levelNumber = 1;
    int levelN = 1;
    queue<TreeNode*> level; 
    level.push(root);
    while(!level.empty()){
        vector<int> temp;
        for (int i = 0; i < levelNumber; i++) {
            TreeNode* node = level.front();
            level.pop();
            temp.push_back(node->val);
            if(node->left != NULL)
                level.push(node->left);
            if(node->right != NULL)
                level.push(node->right);
        }
        if(!temp.empty()){
            if(levelN%2 == 0){
                int low = 0;
                int high = temp.size()-1;
                while(low < high){
                    int temp_num = temp[low];
                    temp[low] = temp[high];
                    temp[high] = temp_num;
                    low++;
                    high--;
                }
            }
            levelNumber = level.size();
            res.push_back(temp);
        }
        levelN++;
    }
    return res;
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

    vector<vector<int> > res;
    res = zigzagLevelOrder(&n1);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    
    
    return 0;
}

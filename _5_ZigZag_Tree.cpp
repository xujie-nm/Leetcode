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

// 使用栈来实现
vector<vector<int> > zigZagTree(TreeNode* root){
    vector<vector<int> > res;
    if(root == NULL){
        return res;
    }

    vector<stack<TreeNode*> > levels(2, stack<TreeNode*>());
    int cur = 0;
    int next = 1;
    
    levels[cur].push(root);
    vector<int> temp;
    while(!levels[0].empty() || !levels[1].empty()){
        TreeNode* node = levels[cur].top();
        levels[cur].pop();

        temp.push_back(node->val);

        if(cur == 0){
            if(node->left != NULL)
                levels[next].push(node->left);
            if(node->right != NULL)
                levels[next].push(node->right);
        }else{
            if(node->right != NULL)
                levels[next].push(node->right);
            if(node->left != NULL)
                levels[next].push(node->left);
        }

        if(levels[cur].empty()){
            res.push_back(temp);
            temp.clear();
            cur = 1-cur;
            next = 1-next;
        }
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
   TreeNode n10(10);
   TreeNode n11(11);
   TreeNode n12(12);
   TreeNode n13(13);
   TreeNode n14(14);
   TreeNode n15(15);

   n1.left = &n2;
   n1.right = &n3;
   n2.left = &n4;
   n2.right = &n5;
   n3.left = &n6;
   n3.right = &n7;
   n4.left = &n8;
   n4.right = &n9;
   n5.left = &n10;
   n5.right = &n11;
   n6.left = &n12;
   n6.right = &n13;
   n7.left = &n14;
   n7.right = &n15;

   vector<vector<int> > res;
   res = zigZagTree(&n1);

   for (int i = 0; i < res.size(); i++) {
       for (int j = 0; j < res[i].size(); j++) {
           cout << res[i][j] << " ";
       }
       cout << endl;
   }
   return 0;
}

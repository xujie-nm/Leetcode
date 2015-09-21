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

//Exceed time
bool hasNode(TreeNode* root, TreeNode* node){
    if(root == NULL)
        return false;
    else if(root->val == node->val)
        return true;
    else
        return hasNode(root->left, node) || hasNode(root->right, node);
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
    if(root == NULL)
        return NULL;
    else if(root->val == p->val)
        return p;
    else if(root->val == q->val)
        return q;
    else if( (hasNode(root->left, p) && hasNode(root->right, q))  
            || (hasNode(root->left, q) && hasNode(root->right, p)))
        return root;
    else if(hasNode(root->left, p) && hasNode(root->left, q))
        return lowestCommonAncestor(root->left, p, q);
    else if(hasNode(root->right, p) && hasNode(root->right, q))
        return lowestCommonAncestor(root->right, p, q);
}

//accpeted
void helper(TreeNode* root, TreeNode* p, TreeNode* q, bool &has_p, bool &has_q, TreeNode** res){
    if(root == NULL)
        return;

    //看左边是否有p，q
    //同时修改结果
    bool has_p_left = false, has_q_left = false;
    helper(root->left, p, q, has_p_left, has_q_left, res);
    //看右边是否有p，q
    //同时修改结果
    bool has_p_right = false, has_q_right = false;
    helper(root->right, p, q, has_p_right, has_q_right, res);

    has_p = has_p_left || has_p_right || root == p;
    has_q = has_q_left || has_q_right || root == q;
    //如果有p，有q，且当前结果为空
    //修改结果
    if(has_p && has_q && *res == NULL)
        *res = root;
}

TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q){
    bool has_p = false, has_q = false;
    TreeNode* res = NULL;
    helper(root, p, q, has_p, has_q, &res);
    return res;
}

int main(int argc, const char *argv[])
{
   TreeNode n3(3); 
   TreeNode n5(5); 
   TreeNode n1(1); 
   TreeNode n6(6); 
   TreeNode n2(2); 
   TreeNode n0(0); 
   TreeNode n8(8); 
   TreeNode n7(7); 
   TreeNode n4(4); 
   n3.left = &n5;
   n3.right = &n1;
   n5.left = &n6;
   n5.right = &n2;
   n1.left = &n0;
   n1.right = &n8;
   n2.left = &n7;
   n2.right = &n4;

   TreeNode* res;
   res = lowestCommonAncestor1(&n3, &n7, &n4);
   cout << "The Ancestor is: " << res->val << endl;
   return 0;
}

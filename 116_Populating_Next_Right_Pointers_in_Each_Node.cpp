#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

void connect(TreeLinkNode *root){
    if(root == NULL)
        return ;
    queue<TreeLinkNode*> level;
    level.push(root);
    int levelNum = 1;
    while(!level.empty()){
        TreeLinkNode* pre = level.front();
        for (int i = 0; i < levelNum; i++) {
            TreeLinkNode* node = level.front();
            level.pop();
            if(pre != node){
                pre->next = node;
                pre = pre->next;
            }
            if(node->left != NULL)
                level.push(node->left);
            if(node->right != NULL)
                level.push(node->right);
        }
        levelNum = level.size();
    }
}

int main(int argc, const char *argv[])
{
    TreeLinkNode n1(1);
    TreeLinkNode n2(2);
    TreeLinkNode n3(3);
    TreeLinkNode n4(4);
    TreeLinkNode n5(5);
    TreeLinkNode n6(6);
    TreeLinkNode n7(7);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = &n6;
    n3.right = &n7;
    
    connect(&n1);
    TreeLinkNode *root = &n1;
    while(root != NULL){
        TreeLinkNode *temp = root;
        while(temp != NULL){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
        root = root->left;
    }

    return 0;
}

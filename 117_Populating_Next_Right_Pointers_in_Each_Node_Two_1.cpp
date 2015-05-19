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
    TreeLinkNode *pseudo = new TreeLinkNode(0);//这是一个辅助的节点
    TreeLinkNode *level = root;//每一层最左边的那个
    while(level != NULL){
        pseudo->next = NULL;
        TreeLinkNode *leaf_head = pseudo;//叶子头，所以pseudo就成了下一层的头节点
        while(level != NULL){
            TreeLinkNode *node = level->left;//开始连接
            if(node != NULL){
                leaf_head->next = node;
                leaf_head = node;
            }
            node = level->right;
            if(node != NULL){
                leaf_head->next = node;
                leaf_head = node;
            }
            level = level->next;//把子节点连接好后，去往下一个，直到把当前层全部连接好
        }
        level = pseudo->next;//去往下一层
    }
}

int main(int argc, const char *argv[])
{
    TreeLinkNode n1(1);
    TreeLinkNode n2(2);
    TreeLinkNode n3(3);
    TreeLinkNode n4(4);
    TreeLinkNode n5(5);
    //TreeLinkNode n6(6);
    TreeLinkNode n7(7);
    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    //n3.left = &n6;
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

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

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

TreeNode* helper(ListNode *head, int low, int high){
    if(low > high)
        return NULL;

    int mid = (low + high)/2;
    int temp_loc = 0;
    ListNode *temp = head;
    while(temp_loc < mid){
        temp = temp->next;
        temp_loc++;
    }
    TreeNode* node = new TreeNode(temp->val);

    node->left = helper(head, low, mid-1);
    node->right = helper(head, mid+1, high);

    return node;
}

TreeNode* sortedArrayToBST(ListNode* head){
    if(head == NULL)
        return NULL;
    int size = 0;
    ListNode *temp = head;
    while(temp != NULL){
        temp = temp->next;
        size++;
    }
    return helper(head, 0, size-1);
}

void inOrder(TreeNode* root){
    if(root == NULL)
        return;

    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

int main(int argc, const char *argv[])
{
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    ListNode n6(6);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;

    TreeNode* root;
    root = sortedArrayToBST(&n1);
    inOrder(root);
    cout << endl;
    return 0;
}

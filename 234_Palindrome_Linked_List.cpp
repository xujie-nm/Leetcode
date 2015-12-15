#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode *head){
    int size = 0;
    ListNode *node = head;
    ListNode* mid = head;
    ListNode* tmp = NULL;
    
    while(node != NULL){
        size++;
        node = node->next;
    }
    
    node = NULL; 

    // 反转前半段
    for (int i = 0; i < size/2; i++) {
        tmp = mid->next;
        mid->next = node;
        node = mid;
        mid = tmp;
    }
    ListNode *right = mid, *left = node;
    if(size % 2 == 1)
        //奇数长度
        right = right->next;
    while(left != NULL && right != NULL){
        if(right->val != left->val)
            return false;
        right = right->next;
        left = left->next;
    }
    return true;
}

int main(int argc, const char *argv[])
{
    ListNode n1(1);
    ListNode n2(1);
    ListNode n3(1);
    ListNode n4(1);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    cout << isPalindrome(&n1) << endl;
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 两个指针，把原来的列表分成两个列表；
// 奇偶数列表，然后连接
ListNode* oddEvenList(ListNode* head){
    if(head == NULL)
        return head;
    ListNode* evenPtrHead = head->next;
    if(evenPtrHead == NULL)
        return head;
    
    ListNode* oddPtr = head;
    ListNode* evenPtr = evenPtrHead;
    ListNode* cur = evenPtrHead->next;
    bool isOdd = true;
    while(cur != NULL){
        if(isOdd){
            oddPtr->next = cur;
            oddPtr = oddPtr->next;
        }else{
            evenPtr->next = cur;
            evenPtr = evenPtr->next;
        }
        cur = cur->next;
        isOdd = !isOdd;
    }
    evenPtr->next = NULL;
    oddPtr->next = evenPtrHead;
    return head;
}

int main(int argc, const char *argv[])
{
    ListNode n1(2);
    ListNode n2(1);
    ListNode n3(4);
    ListNode n4(3);
    ListNode n5(6);
    ListNode n6(5);
    ListNode n7(7);
    ListNode n8(8);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;
    n7.next = &n8;

    ListNode* res;
    res = oddEvenList(&n1);

    while(res != NULL){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}

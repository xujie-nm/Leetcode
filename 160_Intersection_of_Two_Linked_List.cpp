#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

int getLength(ListNode *head){
    int size = 0;
    while(head != NULL){
        size++;
        head = head->next;
    }
    return size;
}

ListNode* getIntersectionNode(ListNode *headA, ListNode *headB){
    int lengthA = getLength(headA);
    int lengthB = getLength(headB);
    
    if(lengthA > lengthB){
        while(lengthA != lengthB){
            headA = headA->next;
            lengthA--;
        }
    }else if(lengthB > lengthA){
        while(lengthB != lengthA){
            headB = headB->next;
            lengthB--;
        }
    }

    while(headB != headA && headA != NULL && headB != NULL){
        headB = headB->next;
        headA = headA->next;
    }
    return headA;
}

int main(int argc, const char *argv[])
{
    ListNode a1(0);
    ListNode a2(0);
    ListNode b1(0);
    ListNode b2(0);
    ListNode b3(0);
    ListNode c1(54);
    ListNode c2(0);
    ListNode c3(0);
    a1.next = &a2;
    a2.next = &c1;
    b1.next = &b2;
    b2.next = &b3;
    b3.next = &c1;
    c1.next = &c2;
    c2.next = &c3;
    
    cout << &c1 << endl;

    ListNode *res = getIntersectionNode(&a1, &b1);

    cout << res << "   " << res->val << endl;
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int val){
    if(head == NULL)
        return head;
    ListNode* Head = new ListNode(0);
    Head->next = head;
    ListNode* pre = Head;
    ListNode* cur = head;

    while(pre->next != NULL){
        if(cur->val == val){
            pre->next = cur->next;
            cur = pre->next;
        }else{
            pre = cur;
            cur = cur->next;
        }
    }
    return Head->next;
}

int main(int argc, const char *argv[])
{
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(6);
    ListNode n4(3);
    ListNode n5(4);
    ListNode n6(5);
    ListNode n7(6);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;
    n6.next = &n7;

    ListNode* res;
    res = removeElements(&n1, 1);
    while(res != NULL){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}

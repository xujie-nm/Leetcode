#include <iostream>
#include <string>
#include <vector>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head){
    if(head == NULL)
        return head;

    ListNode* Head = new ListNode(0);
    while(head != NULL){
        ListNode* temp1 = Head->next;
        ListNode*temp2 = head->next;
        Head->next = head;
        head->next = temp1;
        head = temp2;
    }
    return Head->next;
}

void recurse(ListNode* Head, ListNode* head){
    if(head == NULL)
        return;
    ListNode* temp1 = Head->next;
    ListNode* temp2 = head->next;
    Head->next = head;
    head->next = temp1;
    recurse(Head, temp2);
}

ListNode* reverseList2(ListNode* head){
    ListNode* Head = new ListNode(0);
    recurse(Head, head);
    return Head->next;
}

ListNode* reverseList3(ListNode* head){
    if(head == NULL || head->next == NULL)
        return head;
    ListNode* pre = head;
    ListNode* cur  = pre->next;

    pre->next = NULL;
    while(cur != NULL){
        ListNode* temp = cur->next;
        cur->next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}

int main(int argc, const char *argv[])
{
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);
    ListNode n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    ListNode* res;
    res = reverseList3(&n1);
    while(res != NULL){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}

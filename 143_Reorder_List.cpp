#include <iostream>
#include <string>
#include <deque>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void reorderList(ListNode* head){
    if(head == NULL)
        return ;
    deque<ListNode*> temp;
    ListNode* p = head;
    while(p != NULL){
        temp.push_back(p);
        p = p->next;
    }
    
    temp.pop_front();
    while(!temp.empty()){
        head->next = temp.back();
        head = head->next;
        if(temp.size() == 1)
            head->next = NULL;
        temp.pop_back();
        if(!temp.empty()){
            head->next = temp.front();
            head = head->next;
            if(temp.size() == 1)
                head->next = NULL;
            temp.pop_front();
        }
    }
}

// O(N) time, O(1) space
void reorderList2(ListNode *head){
    if(!head || !head->next)
        return;

    // 找到中间节点:O(n)
    ListNode *p1 = head, *p2 = head->next;
    while(p2 && p2->next){
        p1 = p1->next;
        p2 = p2->next->next;
    }

    // 从中间节点切断，并且把后半部分的链表翻转:O(n)
    ListNode *head2 = p1->next;
    p1->next = NULL;

    p2 = head2->next;
    head2->next = NULL;
    while(p2){
        p1 = p2->next;
        p2->next = head2;
        head2 = p2;
        p2 = p1;
    }

    // 合并前半部分和后半部分:O(n)
    p1 = head;
    p2 = head2;
    while(p1){
        ListNode* temp = p1->next;
        p1->next = p2;
        p1 = p1->next;
        p2 = temp;
    }
}

int main(int argc, const char *argv[])
{
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    n1.next = &n2;
    n2.next = &n3;
    reorderList2(&n1);

    ListNode *p = &n1;
    while(p != NULL){
        cout << p->val << " ";
        p = p->next;
    }
    cout << endl;
    return 0;
}

#include <iostream>
#include <string>
#include <map>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* sortList(ListNode *head){
    if(head == NULL)
        return head;
    multimap<int, ListNode*> table;
    while(head != NULL){
        table.insert(make_pair(head->val, head));
        head = head->next;
    }
    ListNode node(0);
    ListNode *p = &node;
    for(auto it = table.begin(); 
            it != table.end(); it++){
       p->next = it->second;
       p = p->next;
    }
    p->next = NULL;
    return node.next;
}

void Helper(ListNode* head, ListNode* tail){
    if(head->next == tail)
        return;
    //partition
    ListNode* pre = head;
    ListNode* cur = head->next;
    ListNode* pivot = cur;
    while(cur->next != NULL && cur->next != tail){
        //if cut is not tail, no stop
        if(pivot->val > cur->next->val){
            ListNode* temp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = temp;
        }
        else
            cur = cur->next;
    }
    Helper(head, pivot);
    //if val is equal and pivot->next is not tail
    //go next
    while(pivot->next != tail && pivot->next->val == pivot->val)
        pivot = pivot->next;
    if(pivot->next != tail)
        Helper(pivot, tail);
}

ListNode* sortList2(ListNode* head){
    ListNode* p = new ListNode(0);
    p->next = head;
    Helper(p, NULL);
    return p->next;
}

int main(int argc, const char *argv[])
{
    ListNode n1(2);
    ListNode n2(1);
    ListNode n3(3);
    n1.next = &n2;
    n2.next = &n3;

    ListNode* res = sortList2(&n1);
    
    while(res != NULL){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}

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

// merge sort
ListNode* mergeTwoList(ListNode* l1, ListNode* l2){
    if(l1 == NULL)
        return l2;
    else if(l2 == NULL)
        return l1;
    ListNode* head  = new ListNode(0);
    ListNode* temp = head;
    while(l1 && l2){
        if(l1->val < l2->val){
            temp->next = l1;
            temp = temp->next;
            l1 = l1->next;
        }else{
            temp->next = l2;
            temp = temp->next;
            l2 = l2->next;
        }
    }

    if(l1 != NULL){
        temp->next = l1;
    }else if(l2 != NULL){
        temp->next = l2;
    }
    return head->next;
}

ListNode* sortList2(ListNode* head){
    if(!head || !head->next)
        return head;

    ListNode *slow = head;
    ListNode *fast = head;
    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode* leftHalf = head;
    ListNode* rightHalf = slow->next;
    slow->next = NULL;
    ListNode* left = sortList2(leftHalf);
    ListNode* right = sortList2(rightHalf);
    head = mergeTwoList(left, right);
    return head;
}

int main(int argc, const char *argv[])
{
    ListNode n1(2);
    ListNode n2(4);
    ListNode n3(1);
    ListNode n4(3);
    ListNode n5(0);
    ListNode n6(-1);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = &n6;

    ListNode* res = sortList2(&n1);
    
    while(res != NULL){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}

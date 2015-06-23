#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* insertionSortList(ListNode *head){
    if(head == NULL)
        return head;
    ListNode node(0);
    ListNode* cur = head;
    
    while(cur != NULL){
        ListNode *temp = cur;
        ListNode *p = &node;
    
        cur = cur->next;
        temp->next = NULL;
        if(p->next == NULL){
            p->next = temp;
            continue;
        } 
        
        while(p->next != NULL 
                && p->next->val < temp->val){
            p = p->next;
        }
        
        temp->next = p->next;
        p->next = temp;
    }
    return node.next;
}

int main(int argc, const char *argv[])
{
    ListNode n1(5);
    ListNode n2(4);
    ListNode n3(2);
    ListNode n4(1);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    
    ListNode *res = insertionSortList(&n1);
    while(res != NULL){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}

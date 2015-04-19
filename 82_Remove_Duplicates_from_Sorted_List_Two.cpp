#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
  int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode *head){
    if(head == NULL || head->next == NULL)
        return head;
    while(1){
        if(head->next != NULL && head->val == head->next->val){
            while(head->next != NULL && head->val == head->next->val){
                head = head->next;
            }
            if(head->next == NULL)
                return NULL;
            head = head->next;
        }else
            break;
    }

    if(head == NULL || head->next == NULL)
        return head;

    ListNode* temp_head = head;
    ListNode* pre = head;
    while(temp_head->next != NULL){
        if(temp_head->next != NULL && temp_head->val == temp_head->next->val){
            while(temp_head->next != NULL && temp_head->val == temp_head->next->val)
                temp_head = temp_head->next;
            if(temp_head != NULL && temp_head->next != NULL){
                temp_head = temp_head->next;
                pre->next = temp_head;
            }else{
                pre->next = NULL;
                break;
            }
        }else{
            pre = temp_head;
            temp_head = temp_head->next;
        }
    }
    return head;
}

int main(int argc, const char *argv[])
{
    ListNode l1(1); 
    ListNode l2(1); 
    ListNode l3(2); 
    ListNode l4(2); 
    ListNode l5(5); 
    ListNode l6(5); 
    ListNode l7(6); 
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = &l6;
    l6.next = &l7;

    ListNode *head = deleteDuplicates(&l1);
    while(head != NULL){
        cout << head->val << endl;
        head = head->next;
    }

    return 0;
}

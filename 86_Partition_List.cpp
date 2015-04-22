#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode*head, int x){
    if(head == NULL || head->next == NULL)
        return head;
    ListNode* temp1 = NULL;
    ListNode* temp11 = NULL;
    ListNode* temp2 = NULL;
    ListNode* temp22 = NULL;
    
    while(head != NULL){
        if(head->val < x){
            if(temp1 == NULL){
                temp1 = head;
                temp11 = temp1;
            }else{
                temp1->next = head;
                temp1 = temp1->next;
            }
        }else{
            if(temp2 == NULL){
                temp2 = head;
                temp22 = temp2;
            }else{
                temp2->next = head;
                temp2 = temp2->next;
            }
        }
        head = head->next;
    }
    
    if(temp2 != NULL){
        temp2->next = NULL;
        if(temp11 != NULL)
            temp1->next = temp22;
        else
            return temp22;
    }
    return temp11;
}

int main(int argc, const char *argv[])
{
    ListNode l1(1);
    ListNode l2(4);
    ListNode l3(3);
    ListNode l4(2);
    ListNode l5(5);
    ListNode l6(2);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l5;
    l5.next = &l6;

    ListNode* res = partition(&l1, 3);

    //cout << res->val << " " << res->next->val;
    while(res != NULL){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}

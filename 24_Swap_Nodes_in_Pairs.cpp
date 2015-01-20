#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};

ListNode *swapPairs(ListNode *head){
    if(head == NULL)
        return head;
    ListNode *temp = head;
    ListNode *temp_next = temp->next;
    ListNode *pos = NULL;
    while(temp_next != NULL){
        temp->next = temp_next->next;
        temp_next->next = temp;

        if(pos == NULL)
            head = temp_next;
        else
            pos->next = temp_next;

        pos = temp;
        temp = temp->next;
        temp_next = temp != NULL ? temp->next : NULL;
    }
    return head;
}

int main(int argc, const char *argv[])
{
        ListNode f_f(1);
        ListNode f_s(3);
        ListNode f_t(5);
        f_f.next = &f_s;
        f_s.next = &f_t;
            
        ListNode s_f(2);
        ListNode s_s(4);
        ListNode s_t(6);
        s_f.next = &s_s;
        s_s.next = &s_t;

        ListNode *res = swapPairs(&f_f);
        while(res){
            cout << res->val << " ";
            res = res->next;
        }                                                                                               
        cout << endl;
    return 0;
}  

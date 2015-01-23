#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2){
    ListNode *head = new ListNode(0);
    ListNode *temp = head;
    while(l1 != NULL && l2 != NULL){
        if(l1->val < l2->val){
            temp->next = l1;
            l1 = l1->next;
        }else{
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }
    if(l1 != NULL)
        temp->next = l1;
    if(l2 != NULL)
        temp->next = l2;
    temp = head;
    head = head->next;
    delete temp;
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

        ListNode *res = mergeTwoLists(&f_f, &s_f);
        while(res){
            cout << res->val << " ";
            res = res->next;
        }
        cout << endl;
    return 0;
}

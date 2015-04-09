#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode *head, int k){
    int len = 0;
    ListNode* temp = head;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    if(k >= len && len !=0)
        k %= len;
    if(head == NULL || head->next == NULL || k==0 || len==0)                                                                                  
        return head;

    k = len - k;

    ListNode* temp_head = head;
    int i = 0;
    while(i < k-1){
        temp_head = temp_head->next;
        i++;
    }
    ListNode* temp_tail = temp_head;
    ListNode* real_head = temp_head->next;
    while(temp_head->next != NULL){
        temp_head = temp_head->next;
    }
    temp_tail->next = NULL;
    temp_head->next = head;
    return real_head;
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
    //n3.next = &n4;
    n4.next = &n5;
    cout << "before" << endl;
    ListNode *ll = &n1;
    while(ll != NULL){
        cout << ll->val << " ";
        ll = ll->next;
    }
    cout << endl << "after" << endl;
    ListNode* res = rotateRight(&n1, 2000000000);
    while(res != NULL){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}

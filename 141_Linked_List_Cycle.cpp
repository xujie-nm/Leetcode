#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head){
    if(head == NULL)
        return false;
    ListNode *back = head;
    head = head->next;
    
    while(head != NULL && head->next != NULL){
        if(head == back)
            return true;
        head = head->next->next;
        back = back->next;
    }
    return false;
}

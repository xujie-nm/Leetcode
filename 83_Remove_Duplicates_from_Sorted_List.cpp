#include <iostream>
#include <string>
#include <vector>
using namespace std;


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL)
            return NULL;
        ListNode* temp_head = head;
        while(temp_head->next != NULL){
            if(temp_head->val == temp_head->next->val){
                temp_head->next = temp_head->next->next; 
            }
            else{
                temp_head = temp_head->next;
            }
        }
        return head;
    }
};

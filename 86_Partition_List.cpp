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
    // 把一个链表分成两个链表
    // temp11为链表一的头
    // temp1为链表一的尾
    // temp22为链表二的头
    // temp2为链表二的尾
    // 最后再把两个链表连接起来
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
// faster
// 但是不会保持相对位置
ListNode* partition2(ListNode* head, int x){
    if(head == NULL || head->next == NULL)
        return head;
    int countSmall = 0;
    int size = 0;
    ListNode* temp1 = head;
    while(temp1 != NULL){
        if(temp1->val < x)
            countSmall++;
        size++;
        temp1 = temp1->next;
    }
    if(countSmall == 0 || countSmall == size)
        return head;

    temp1 = head;
    while(countSmall > 0){
        temp1 = temp1->next;
        countSmall--;
    }
    ListNode* temp2 = head;
    ListNode* mid = temp1;
    while(temp1 != NULL && temp2 != mid){
        if(temp2->val >= x && temp1->val < x){
            int temp = temp1->val;
            temp1->val = temp2->val;
            temp2->val = temp;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }else if(temp2->val >= x){
            temp1 = temp1->next;
        }else if(temp1->val < x){
            temp2 = temp2->next;
        }else{
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    return head;
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

    ListNode* res = partition2(&l1, 3);

    //cout << res->val << " " << res->next->val;
    while(res != NULL){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}

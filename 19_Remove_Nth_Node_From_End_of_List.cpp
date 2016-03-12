#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

ListNode *removeNthFromEnd(ListNode *head, int n){
    int length = 0;
    ListNode *temp = head;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }

    if(n > length)
        return NULL;
    else if(n == length)
    {
        head = head->next;
        return head;
    }
    int pos = length - n - 1;
    temp = head;
    while(pos > 0){
        temp = temp->next;
        pos--;
    }
    ListNode * del = temp->next;
    temp->next = del->next;
    return head;
}

// Two Pointer
ListNode* removeNthFromEnd2(ListNode* head, int n){
    int i = 0;
    ListNode *first = head;
    ListNode *second = head;

    while(i < n && first != NULL){
        i++;
        first = first->next;
    }

    if(i != n){
        return NULL;
    }
    
    // 如果删除的是头一个
    if(first != NULL)
        first = first->next;
    else
        return head->next;

    while(first != NULL){
        first = first->next;
        second = second->next;
    }

    // 删除
    second->next = second->next->next;

    return head;
}

int main(int argc, const char *argv[])
{
    ListNode first(1);
    ListNode second(2);
    ListNode third(3);
    ListNode fourth(4);
    ListNode fifth(5);
    first.next = &second;
    second.next = &third;
    third.next = &fourth;
    fourth.next = &fifth;
    ListNode *res = removeNthFromEnd2(&first, 1);
    cout << "ok ok ok ok ok ok ok " << endl;
    while(res != NULL){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}

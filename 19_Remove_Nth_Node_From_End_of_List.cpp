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
    ListNode *res = removeNthFromEnd(&first, 4);
    cout << "ok ok ok ok ok ok ok " << endl;
    while(res != NULL){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}

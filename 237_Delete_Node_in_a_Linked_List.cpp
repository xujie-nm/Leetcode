#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node){
    node->val = node->next->val;
    node->next = node->next->next;
}

int main(int argc, const char *argv[])
{
    ListNode n1(1);
    ListNode n2(2);
    ListNode n3(3);
    ListNode n4(4);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;

    deleteNode(&n3);
    ListNode *node = &n1;
    while(node != NULL){
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
    return 0;
}

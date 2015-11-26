#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head){
    if(head == NULL)
        return NULL;
    
    unordered_set<ListNode*> nodes;
    while(head != NULL){
        if(nodes.count(head) > 0)
            return head;
        nodes.insert(head);
        head = head->next;
    }
    return NULL; 
}

ListNode *detectCycle2(ListNode *head){
    ListNode *slow = head;
    ListNode *fast = head;
    while(fast != NULL && fast->next){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast){
            //这里的原理：
            //假设link长为n，在ｉ处开始cycle的话，
            //那么当slow到i＋１处时，走了ｉ步，fast的位置是(n-i+1-i)%(n-i+1),走了2(i)
            //那么设他们再走x步相遇，则有
            //(i+x)%(n-i+1) = (i+2x)%(n-i+1)
            //所以ｘ必须是(n-i+1)的整数倍上式子相等
            //所以相遇的位置还是起始的位置，此时的位置是(n-i+1-i)%(n-i+1),还需要ｉ部就能得到
            //n-i+1，所以此时开头的slow正好走ｉ部到cycle的开头
            slow = head;
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

// space O(1)
ListNode* reverse(ListNode *root){
    if(root && root->next){
        ListNode *next = root->next, *nextNext = root->next->next;
        root->next = NULL;
        while(next){
            next->next = root;
            root = next;
            next = nextNext;
            nextNext = next ? next->next : NULL;
        }
    }
    return root;
}

void reorderList(ListNode* head){
    // 计算链表的大小
    int n = 0;
    ListNode *temp = head;
    while(temp){
        temp = temp->next;
        n++;
    }
    if(n <= 2)
        return;

    // 把后半部分翻转
    int half = (n+3)/2 -1;
    temp = head;
    while(half){
        temp = temp->next;
        half--;
    }
    temp = reverse(temp);

    // 合并
    ListNode *tempNext = temp->next;
    while(temp){
        temp->next = head->next;
        head->next = temp;
        head = temp->next;
        temp = tempNext;
        tempNext = temp ? temp->next : NULL;
    }
    if(head)
        head->next = NULL;
}

int main(int argc, const char *argv[])
{
    ListNode n1(1);
    ListNode n2(2);
    n1.next = &n2;

    ListNode *res = detectCycle2(&n1);
    if(res == NULL)
        cout << "no Cycle" << endl;
    else
        cout << "start: " << res->val << endl;
    return 0;
}

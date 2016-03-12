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
            // 这里的原理：
            //                |------------->|              
            //             p3 | ------------*<-
            //                | |           | |
            //                | |           | |
            //                | |           | |
            //                | |           | |  p2
            //                > |           | |
            // ------------------------------ |
            // ^                ^             |
            // |----------------|-------------
            //         p1
            //
            // 设环的长度为 c，快指针速度为 2，慢指针速度为 1，
            // 设相遇时走的时间为 t
            //     p1 代表链表起点距离环起点的距离
            //     p2 代表在环中快慢指针相遇距离环起点的位置
            //     p3 代表c-p2
            // 所以有下列关系
            //     2t - t = k1 * c (k1为1，2，3，4，5 .....)
            // 所以
            //     t = k1 * c
            //     p1 + k2 * c + p2 = k1 * c (k2为0，1，2，3，....且k1 > k2)
            // 所以
            //     p1 + p2 = K * c (设K = k1 - k2, K 的取值为 1，2，3，4，5...)
            // 所以
            //     p3 = c - p2 = p1 + (1-K)*c
            // 所以
            //     p1 = p3 + (K-1)*c
            // 所以这就是为什么最后要把两个快慢指针的速度置为相同后让一个指针从开始走
            // 两个指针最后能相遇的原因
            // 也是相遇位置就是环开头的原因
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
    ListNode n3(2);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n2;

    ListNode *res = detectCycle2(&n1);
    if(res == NULL)
        cout << "no Cycle" << endl;
    else
        cout << "start: " << res->val << endl;
    return 0;
}

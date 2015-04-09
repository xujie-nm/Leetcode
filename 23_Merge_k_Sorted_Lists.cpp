#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x), next(NULL){}
};

ListNode *mergeKLists(vector<ListNode *> &lists){
    if(lists.empty())
        return NULL;
    if(lists[0] == NULL && lists.size() == 1)
        return NULL;
   
    ListNode *head = new ListNode(0);
    ListNode *temp = head;
    multimap<int, ListNode*> temp_map;
    
    for(vector<ListNode *>::iterator it = lists.begin(); it != lists.end(); ++it){
        if((*it) != NULL)
            temp_map.insert(make_pair((*it)->val, *it));
    }
    
    while(!temp_map.empty()){
        multimap<int, ListNode*>::iterator temp_it = temp_map.begin();
        temp->next = temp_it->second;
        temp = temp->next;
        temp_map.erase(temp_it);
        if(temp->next != NULL){
            temp_map.insert(make_pair(temp->next->val, temp->next));
        }
    }
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

        vector<ListNode*> lists;
        lists.push_back(&f_f);
        lists.push_back(&s_f);
        ListNode *res = mergeKLists(lists);
        while(res){
                    cout << res->val << " ";
                    res = res->next;
                }   
        cout << endl;
    return 0;
}     

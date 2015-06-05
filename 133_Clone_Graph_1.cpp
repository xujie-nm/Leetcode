#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node){
    if(node == NULL)
        return NULL;
    map<UndirectedGraphNode *, UndirectedGraphNode *> has;
    UndirectedGraphNode* newNode = new UndirectedGraphNode(node->label);
    has[node] = newNode;
    queue<UndirectedGraphNode *> q;
    q.push(node);

    while(!q.empty()){
        UndirectedGraphNode* temp = q.front();
        q.pop();

        for (int i = 0; i < temp->neighbors.size(); i++) {
            if(has.count(temp->neighbors[i]) == 0){
                UndirectedGraphNode* newNode1 = new UndirectedGraphNode(temp->neighbors[i]->label);
                has[temp->neighbors[i]] = newNode1;
                has[temp]->neighbors.push_back(newNode1);
                q.push(temp->neighbors[i]);
            }else{
                has[temp]->neighbors.push_back(has[temp->neighbors[i]]);
            }
        }
    }
    return newNode;
}

int main(int argc, const char *argv[])
{
    UndirectedGraphNode n1(1);    
    UndirectedGraphNode n2(0);    
    UndirectedGraphNode n3(2);  
//    n1.neighbors.push_back(&n2);
//    n1.neighbors.push_back(&n3);
//    n2.neighbors.push_back(&n1);
//    n2.neighbors.push_back(&n3);
//    n3.neighbors.push_back(&n1);
//s    n3.neighbors.push_back(&n2);
//    n3.neighbors.push_back(&n3);
    cloneGraph(&n1);
    return 0;
}

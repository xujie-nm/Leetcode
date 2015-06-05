#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
//TLE

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

void helper(UndirectedGraphNode *node, 
        UndirectedGraphNode *node1, 
        map<UndirectedGraphNode*, UndirectedGraphNode*> has){
    int oldsize = has.size();
    for (int i = 0; i < node->neighbors.size(); i++) {
        if(has.count(node->neighbors[i]) == 0){
            UndirectedGraphNode newNode(node->neighbors[i]->label);
            has[node->neighbors[i]] = &newNode;
            helper(node->neighbors[i], &newNode, has);
        }
        node1->neighbors.push_back(node->neighbors[i]);
    }
    if(oldsize == has.size())
        return;
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node){
    if(node == NULL)
        return NULL;
    map<UndirectedGraphNode *, UndirectedGraphNode *> has;
    UndirectedGraphNode newNode(node->label);
    has[node] = &newNode;
    helper(node, &newNode, has);
    return &newNode;
}

int main(int argc, const char *argv[])
{
    UnfirectedGraphNode n1(1);    
    UnfirectedGraphNode n2(0);    
    UnfirectedGraphNode n3(2);  
    n1.neighbors.push_back(&n2);
    n1.neighbors.push_back(&n3);
    n2.neighbors.push_back(&n1);
    n2.neighbors.push_back(&n3);
    n3.neighbors.push_back(&n1);
    n3.neighbors.push_back(&n2);
    n3.neighbors.push_back(&n3);
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

/*
 *  // This is the interface that allows for creating nested lists.
 *  // You should not implement it, or speculate about its implementation
 *  class NestedInteger{
 *      public:
 *          // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *          bool isInteger() const;
 *
 *          // Return the single inetger that this NestedInteger holds, if it holds a single integer
 *          int getInteger() const;
 *
 *          // Return the nested list that this NestedInteger holds, if it holds a nested list
 *          // The result is undefined if this NestedInteger holds a single integer
 *          const vector<NestedInteger> &getList() const;
 *  };
 */

class NestedIterator{
    private:
        stack<NestedInteger> nodes;

    public:
        NestedIterator(vector<NestedInteger> &nestedList){
            for (int i = nestedList.size()-1; i >= 0; i--)
                nodes.push(nestedList[i]);
        }

        int next(){
            int result = nodes.top().getInteger();
            nodes.pop();
            return result;
        }

        bool hasNext(){
            while(!nodes.empty()){
                NestedInteger cur = nodes.top();
                vector<NestedInteger>& adjs = cur.getList();
                bool isInteger = false;
                if(!cur.isInteger()){
                    nodes.pop();
                    isInteger = false;
                }else
                    isInteger = true;
                
                for (int i = adjs.size()-1; i >= 0; i--) 
                    nodes.push(adjs[i]);
                if(isInteger)
                    return true;
            }
            return false;
        }
};

/**
 * Your NestedInteger object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while(i.hasNext())
 *     cout << i.next() << endl;

#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Stack{
public:
    //Push element x onto stack
    void push(int x);

    //Removes the elements on top of the stack
    void pop();

    //Get the top element
    int top();

    //Return whether the stack is empty
    bool empty();

private:
    queue<int> q1;
    queue<int> q2;
};

void Stack::push(int x){
    if(q1.empty()){
        q2.push(x);
    }
    else{
        q1.push(x);
    }
}

void Stack::pop(){
    if(!q1.empty()){
        while(q1.size() > 1){
            int temp = q1.front();
            q1.pop();
            q2.push(temp);
        }
        q1.pop();
        return;
    }
    else if(!q2.empty()){
        while(q2.size() > 1){
            int temp = q2.front();
            q2.pop();
            q1.push(temp);
        }
        q2.pop();
        return;
    }
}


int Stack::top(){
    if(!q1.empty()){
        while(q1.size() > 1){
            int temp = q1.front();
            q1.pop();
            q2.push(temp);
        }
        int res = q1.front();
        q1.pop();
        q2.push(res);
        return res;
    }
    else if(!q2.empty()){
        while(q2.size() > 1){
            int temp = q2.front();
            q2.pop();
            q1.push(temp);
        }
        int res = q2.front();
        q2.pop();
        q1.push(res);
        return res;
    }
    else
        return -1;
}

bool Stack::empty(){
    return q1.empty() && q2.empty();
}

int main(int argc, const char *argv[])
{
    Stack s;
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.pop();
    s.push(9);
    while(!s.empty()){
        cout << s.top() << endl;
        s.pop();
    }
    return 0;
}

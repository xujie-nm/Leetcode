#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class Queue{
    public:
        //Push element x to the back of queue
        void push(int x);

        //Removes the element from in front of queue
        void pop();

        //Get the front element
        int peek();

        //Return whether the queue is empty
        bool empty();

    private:
        stack<int> data;
        stack<int> temp;
};

void Queue:: push(int x){
    data.push(x);
}

void Queue:: pop(){
    if(data.empty())
        return;
    while(data.size() > 1){
        temp.push(data.top());
        data.pop();
    }
    data.pop();
    while(!temp.empty()){
        data.push(temp.top());
        temp.pop();
    }
}

int Queue::peek(){
    int res;
    if(data.empty())
        return -1;
    while(data.size() > 1){
        temp.push(data.top());
        data.pop();
    }
    res = data.top();
    temp.push(data.top());
    data.pop();
    while(!temp.empty()){
        data.push(temp.top());
        temp.pop();
    }
    return res;
}

bool Queue::empty(){
    return data.empty();
}

int main(int argc, const char *argv[])
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    while(!q.empty()){
        cout << q.peek() << " " << endl;
        q.pop();
    }
    cout << endl;
    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class MinStack{
    public:
        void push(int x);
        void pop();
        int top();
        int getMin();
    private:
        vector<int> array;
        map<int, int> temp;
};

void MinStack:: push(int x){
    array.push_back(x);
    temp[x]++;
}

void MinStack:: pop(){
    int last = array.back();
    if(temp[last] == 1)
        temp.erase(last);
    else
        temp[last]--;
    array.pop_back();
}

int MinStack:: top(){
   return array.back(); 
}

int MinStack:: getMin(){

    return (temp.begin())->first;    
}

int main(int argc, const char *argv[])
{
    MinStack s1;
    s1.push(3);
    s1.push(1);
    s1.push(2);
    s1.push(4);
    cout << s1.top() << endl;
    s1.pop();
    cout << s1.top() << endl;
    cout << s1.getMin() << endl;
    return 0;
}

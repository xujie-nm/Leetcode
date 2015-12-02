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

// 使用一个min数组来存储0~i之间的最小值
class MinStack2{
    public:
        void push(int x){
            nums.push_back(x);
            if(mins.empty()){
                mins.push_back(x);
            }else{
                if(x < mins.back()){
                    mins.push_back(x);
                }else{
                    mins.push_back(mins.back());
                }
            }
        }

        void pop(){
            if(!nums.empty() && !mins.empty()){
                nums.pop_back();
                mins.pop_back();
            }
        }

        int top(){
            return nums.back();
        }

        int getMin(){
            return mins.back();
        }

    private:
        vector<int> nums;
        vector<int> mins;
};

int main(int argc, const char *argv[])
{
    MinStack2 s1;
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

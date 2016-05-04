#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

class MovingAverage{
    private:
        queue<int> que;
        double sum;
    
    public:

        MovingAverage(): sum(0){
        }

        double Average(){
            if(que.empty())
                return 0;
            else
                return sum/(que.size());
        }

        void push(int element){
            que.push(element);
            sum += element;
        }

        int front(){
            return que.front();
        }

        void pop(){
            if(!que.empty()){
                sum -= front();
                que.pop();
            }
        }
};

int main(int argc, const char *argv[])
{
    MovingAverage ma;
    cout << ma.Average() << endl;
    ma.push(1);
    cout << ma.Average() << endl;
    ma.push(2);
    cout << ma.Average() << endl;
    ma.push(3);
    cout << ma.Average() << endl;
    ma.push(4);
    cout << ma.Average() << endl;
    ma.push(5);
    cout << ma.Average() << endl;
    ma.pop();
    cout << ma.Average() << endl;
    ma.pop();
    cout << ma.Average() << endl;
    ma.pop();
    cout << ma.Average() << endl;
    ma.pop();
    cout << ma.Average() << endl;
    ma.pop();
    cout << ma.Average() << endl;
    ma.pop();
    cout << ma.Average() << endl;
    return 0;
}

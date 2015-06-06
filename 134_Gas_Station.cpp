#include <iostream>
#include <string>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int> &gas, vector<int> &cost){
    int sum = 0;
    int start = 0;
    int index = 0;
    for (int i = 0; i < gas.size(); i++) {
        sum += gas[i] - cost[i];//记录当前剩余gas的和
        start += gas[i] - cost[i];//记录从上次位置出发到目前位置的剩余gas
        if(start < 0){
            //如果小于０，说明从上次到目前是不可达的
            //重置起始位置和当前剩余gas
            index = i+1;
            start = 0;
        }
    }
    //如果总体的剩余gas小于０．说明不可能到达
    return sum < 0 ? -1 : index;
}

int main(int argc, const char *argv[])
{
    vector<int> gas;
    vector<int> cost;
    gas.push_back(2);
    gas.push_back(4);
    /*gas.push_back(1);
    gas.push_back(2);
    gas.push_back(3);
    gas.push_back(4);
    gas.push_back(0);*/
    cost.push_back(3);
    cost.push_back(4);
    /*cost.push_back(0);
    cost.push_back(0);
    cost.push_back(0);
    cost.push_back(0);
    cost.push_back(11);*/
    cout <<"res: " <<  canCompleteCircuit(gas, cost) << endl;
    return 0;
}

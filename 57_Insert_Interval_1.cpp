#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };
 

bool comp1(const Interval &lhs, const Interval &rhs){
    return lhs.start < rhs.start;
}

bool comp2(const Interval &lhs, const Interval &rhs){
    return lhs.end < rhs.end;
}

vector<Interval> insert(vector<Interval> &intervals, Interval newInterval){
    vector<Interval>::iterator begin = lower_bound(intervals.begin(), intervals.end(), newInterval, comp1);
    if(begin != intervals.begin() && (begin - 1)->end >= newInterval.start){
        --begin;
        newInterval.start = begin->start;
    }
    //找到start的下邊界所在的迭代器
    //並替換begin

    vector<Interval>::iterator end = lower_bound(intervals.begin(), intervals.end(), newInterval, comp2);
    if(end != intervals.end() && end->start <= newInterval.end){
        newInterval.end = end->end;
        ++end;
    }
    //找到end的下邊界所在的迭代器
    //並替換end
    
    vector<Interval>:: iterator t = intervals.erase(begin, end);
    //需要刪除已經佔到的


    intervals.insert(t, newInterval);
    //並在所在位置插入新的

    return intervals;
}

int main(int argc, const char *argv[])
{
    Interval intr1(1, 3); 
    Interval intr2(2, 6); 
    Interval intr3(8, 10);
    Interval intr4(15, 18);
    vector<Interval> intervals;
    intervals.push_back(intr1);
    intervals.push_back(intr2);
    intervals.push_back(intr3);
    intervals.push_back(intr4);

    vector<Interval> res = insert(intervals, Interval(3, 10));
    for(vector<Interval>::iterator it = res.begin(); it != res.end(); ++it){
        cout << "[ "<< (*it).start << ", "<< (*it).end << " ]"<< endl;    
    }


  
    return 0;
}

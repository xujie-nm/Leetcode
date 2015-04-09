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

bool comp(const Interval &a, const Interval &b){
    return a.start < b.start;
}
 
vector<Interval> merge(vector<Interval> &intervals){
    vector<Interval> res;
    if(intervals.empty())
        return res;
    sort(intervals.begin(), intervals.end(), comp);
    res.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        if(res.back().end >= intervals[i].start){
            int start = res.back().start;
            int end = (res.back().end > intervals[i].end ? res.back().end : intervals[i].end);
            res.pop_back();
            res.push_back(Interval(start, end));
        }else
            res.push_back(intervals[i]);
    }
    return res;
}

vector<Interval> insert(vector<Interval> &intervals, Interval newinterval){
    intervals.push_back(newinterval);
    return merge(intervals);
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

    vector<Interval> res;
    res = merge(intervals);

    for(vector<Interval>::iterator it = res.begin(); it != res.end(); ++it){
        cout << "[ "<< (*it).start << ", "<< (*it).end << " ]"<< endl;    
    }
    
    cout << "after insert" << endl;

    res = insert(res, Interval(3, 10));
    for(vector<Interval>::iterator it = res.begin(); it != res.end(); ++it){
        cout << "[ "<< (*it).start << ", "<< (*it).end << " ]"<< endl;    
    }

    return 0;
}

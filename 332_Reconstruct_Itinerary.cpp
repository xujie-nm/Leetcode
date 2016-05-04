#include <iostream>
#include <string>

#include <vector>
#include <map>
#include <set>

#include <algorithm>
using namespace std;

void helper(vector<string>& res, map<string, multiset<string> >& path, string curDes){
    // 一直走一直走到走不下去了才开始压入数列
    // 走不下去了说明这是最后的一个
    while(path[curDes].size()){
        string nextDes = *path[curDes].begin();
        path[curDes].erase(path[curDes].begin());
        helper(res, path, nextDes);
    }
    res.push_back(curDes);
}

vector<string> findItinerary(vector<pair<string, string> > tickets){
    vector<string> res;
    if(tickets.size() <= 0)
        return res;
    map<string, multiset<string> > path;
    for (int i = 0; i < tickets.size(); i++) {
        path[tickets[i].first].insert(tickets[i].second);
    }

    string curDes = "JFK";
    helper(res, path, curDes);
    reverse(res.begin(), res.end());
    return res;
}

int main(int argc, const char *argv[])
{
    vector<pair<string, string> > tickets;
    //tickets.push_back(make_pair("JFK", "KUL"));
    //tickets.push_back(make_pair("JFK", "NRT"));
    //tickets.push_back(make_pair("NRT", "JFK"));
    //tickets.push_back(make_pair("ATL", "JFK"));
    //tickets.push_back(make_pair("ATL", "SFO"));
    tickets.push_back(make_pair("JFK", "SFO"));
    tickets.push_back(make_pair("JFK", "ATL"));
    tickets.push_back(make_pair("SFO", "ATL"));
    tickets.push_back(make_pair("ATL", "JFK"));
    tickets.push_back(make_pair("ATL", "SFO"));

    vector<string> res;
    res = findItinerary(tickets);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    cout << endl;
    return 0;
}

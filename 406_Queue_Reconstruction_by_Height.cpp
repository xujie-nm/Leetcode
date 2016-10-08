#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

static bool comp(const pair<int, int>& p1, const pair<int, int>& p2)
{
    return p1.first > p2.first 
        || (p1.first == p2.first && p1.second < p2.second);
}

vector<pair<int, int> > reconstructQueue(vector<pair<int, int> >& people)
{
    vector<pair<int, int> > res;
    sort(people.begin(), people.end(), comp);

    for (int i = 0; i < people.size(); i++) 
    {
        bool add = true;
        int countBig = 0;
        for (int j = 0; j < res.size(); j++) 
        {
            if(res[j].first >= people[i].first)
            {
                countBig++;
            }
            if(countBig > people[i].second)
            {
                res.insert(res.begin()+j, people[i]);
                add = false;
                break;
            }
        }
        if(add){
            res.push_back(people[i]);
        }
    }

    return res;
}

vector<pair<int, int> > reconstructQueue1(vector<pair<int, int> >& people)
{
    vector<pair<int, int> > res;
    sort(people.begin(), people.end(), comp);

    for(auto& item : people)
    {
        res.insert(res.begin() + item.second, item);
    }

    return res;
}

int main(int argc, const char *argv[])
{
    vector<pair<int, int> > people;
    people.push_back(make_pair(7,0));
    people.push_back(make_pair(4,4));
    people.push_back(make_pair(7,1));
    people.push_back(make_pair(5,0));
    people.push_back(make_pair(6,1));
    people.push_back(make_pair(5,2));

    people = reconstructQueue(people);
    for (int i = 0; i < people.size(); i++) {
        cout << "[ " << people[i].first << ", " << people[i].second << "]\n";
    }
       
    return 0;
}

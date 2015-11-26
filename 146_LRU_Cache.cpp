#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

// map<key, pair<list::iterator, value> >
// list<k>
class LRUCache{
    public:
        LRUCache(int capacity):size(capacity){};

        int get(int key);

        void set(int key, int value);
    private:
        typedef unordered_map<int, pair<list<int>:: iterator, int> > Hash;
        list<int> lruData;
        Hash hash;
        int size;
};

int LRUCache::get(int key){
    auto res = hash.find(key);
    if(res == hash.end())
        return -1;
    else{
        lruData.erase(res->second.first);
        lruData.push_front(res->first);
        res->second.first = lruData.begin();
        return res->second.second;
    }
}

void LRUCache::set(int key, int value){
    auto res = hash.find(key);
    if(res != hash.end()){
        lruData.erase(res->second.first);
        lruData.push_front(res->first);
        res->second.first = lruData.begin();
        res->second.second = value;
        return;
    }

    if(hash.size() == size){
        hash.erase(lruData.back());
        lruData.pop_back();
    }
    lruData.push_front(key);
    hash[key] = make_pair(lruData.begin(), value);
    return ;
}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Below is the interface for Iterator, which is already defined for you.
// **DO NOT** modify the interface for Iterator.
class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    // Returns the next element in the iteration.
    int next();
    // Returns true if the iteration has more elements.
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
    bool peeked;
    int peekElement;

    public:
        PeekingIterator(const vector<int>& nums) : Iterator(nums) {
            // Initialize any member here.
            // **DO NOT** save a copy of nums and manipulate it directly.
            // You should only use the Iterator interface methods.
            peeked = false;
        }

        // Returns the next element in the iteration without advancing the iterator.
        int peek() {
            if(!peeked && Iterator::hasNext()){
                peeked = true;
                peekElement = Iterator::next();
                return peekElement;
            }else if(peeked)
                return peekElement;
        }

        // hasNext() and next() should behave the same as in the Iterator interface.
        // Override them if needed.
        int next() {
            if(peeked){
                peeked = false;
                return peekElement;
            }
            if(Iterator::hasNext())
                return Iterator::next();
        }

        bool hasNext() const {
            if(peeked)
                return true;
            return Iterator::hasNext();
        }
};

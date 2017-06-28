#include <iostream>
#include <vector>
using namespace std;



  // This is the interface that allows for creating nested lists.
  // You should not implement it, or speculate about its implementation
class NestedInteger {
public:
	 //  Return true if this NestedInteger holds a single integer, rather than a nested list.
     bool isInteger() const;

     //  Return the single integer that this NestedInteger holds, if it holds a single integer
     // The result is undefined if this NestedInteger holds a nested list
     int getInteger() const;

	 //  Return the nested list that this NestedInteger holds, if it holds a nested list
	 //  The result is undefined if this NestedInteger holds a single integer
     const vector<NestedInteger> &getList() const;
};

class NestedIterator {
public:

    void traverseNestList(vector<int>& list, const vector<NestedInteger>& nestedList) {
        size_t size = nestedList.size();
        for(auto i: nestedList) {
            if (i.isInteger()) {
                list.push_back(i.getInteger());
            } else {
                traverseNestList(list,i.getList());
            }
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        traverseNestList(list, nestedList);
        currentIndex = 0;
        listSize = list.size();
    }

    int next() {
        return list[currentIndex++];
    }

    bool hasNext() {
        if (currentIndex < listSize)
            return true;
        else
            return false;
    }

private:
    vector<int> list;
    int currentIndex;
    size_t listSize;
};


//  Your NestedIterator object will be instantiated and called as such:
//  NestedIterator i(nestedList);
//  while (i.hasNext()) cout << i.next();
//

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
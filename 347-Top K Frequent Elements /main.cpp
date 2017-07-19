#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:

    static int cmp(const pair<int, int>& a,const pair<int, int>& b) {
        return a.second>b.second || (a.second==b.second && a.first < b.first);
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> counter;
        for(auto i: nums) {
            if (counter[i] > 0)
                counter[i] += 1;
            else
                counter[i] = 1;
        }
        vector<pair<int, int> > counterVector;
        map<int, int>::iterator mapIter = counter.begin();
        for(; mapIter != counter.end(); mapIter ++) {
            counterVector.push_back(pair<int, int>(mapIter->first, mapIter->second));
        }
        sort(counterVector.begin(), counterVector.end(), cmp);
        vector<int> result;
        for(int i = 0; i < k; i ++) {
            result.push_back(counterVector[i].first);
        }
        return result;
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
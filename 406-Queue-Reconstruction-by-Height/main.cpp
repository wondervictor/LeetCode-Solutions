#include <iostream>
#include <vector>

using std::pair;
using std::vector;



class Solution {
public:

    static bool compare(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first || a.first == b.first && a.second < b.second;
    }

    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> result;
        size_t size = people.size();
        std::sort(people.begin(),people.end(),compare);
        for(auto i: people) {
            vector<pair<int, int>>::iterator be = result.begin();
            result.insert(be+i.second, i);
        }
        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
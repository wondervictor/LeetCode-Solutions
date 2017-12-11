#include <iostream>
#include <map>

using std::map;
using std::vector;
using std::string;



class Solution {
public:
    string frequencySort(string s) {
        string result;

        map<char, int> counter;
        for(auto i: s) {
            counter[i] += 1;

        }

        return result;
    }
};


int main() {
    Solution sol;
    sol.frequencySort("treeerreetdssddesrsgdc");

    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
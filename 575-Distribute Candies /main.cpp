#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        map<int, int> cans;
        for (auto i: candies) {
            if (cans[i] > 0)
                cans[i] += 1;
            else
                cans[i] = 1;
        }
        int typeSize = (int)cans.size();
        int numSize = (int)candies.size();
        return typeSize > numSize/2 ? numSize/2 : typeSize;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
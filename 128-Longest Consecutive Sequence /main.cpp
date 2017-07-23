#include <iostream>
#include <vector>
#include <set>

using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        set<int> numbers;
        for(auto i: nums) {
            numbers.insert(i);
        }

        int length = 1;
        int maxLength = 0;
        set<int>::iterator iterr = numbers.begin();
        int previous = *iterr;
        iterr ++;
        for(; iterr != numbers.end(); iterr ++) {
            if (*iterr == previous+1) {
                length ++;
            } else {
                maxLength = maxLength > length ? maxLength : length;
                length = 1;
            }
            previous = *iterr;
        }

        maxLength = maxLength > length ? maxLength : length;
        return maxLength;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
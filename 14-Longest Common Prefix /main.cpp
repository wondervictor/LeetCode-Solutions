#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix;
        int size = (int)strs.size();
        if (size == 0) {
            return prefix;
        }
        prefix = strs[0];
        if (size == 1) {
            return prefix;
        }

        for(int m = 1; m <  size; m ++) {
            prefix = "";
            string previousPrefix = strs[m-1];
            for(int i = 0; i < previousPrefix.size() && i < strs[m].size(); i ++) {
                if (previousPrefix[i] == strs[m][i]) {
                    prefix.push_back(strs[m][i]);
                } else {
                    break;
                }
            }
            strs[m] = prefix;
        }
        return prefix;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
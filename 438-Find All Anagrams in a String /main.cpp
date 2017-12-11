#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:

    // TLE
    bool check(map<char, int> pattenCounter, string& s, int start, int pattenLength) {
        int tmp = pattenLength;
        for(int i = 0; i < pattenLength; i ++) {
            if (pattenCounter[s[i+start]] > 0) {
                tmp --;
                pattenCounter[s[i+start]] -= 1;
            } else {
                return false;
            }
        }
        return tmp == 0;
    }

    // TLE
    vector<int> findAnagramsTLE(string s, string p) {
        int pattenLength = (int)p.size();
        map<char, int> pattenCounter;
        for(auto i: p) {
            if (pattenCounter[i] > 0) {
                pattenCounter[i] += 1;
            } else {
                pattenCounter[i] = 1;
            }
        }
        int size = (int)s.size();
        vector<int> indexes;
        for(int i = 0; i <= size-pattenLength; i ++) {
            if (check(pattenCounter,s,i,pattenLength)) {
                indexes.push_back(i);
            }
        }
        return indexes;
    }

    vector<int> findAnagrams(string s, string p) {
        int pattenLength = (int)p.size();
        int size = (int)s.size();
        if (!size)
            return {};
        vector<int> result;
        int left = 0, right = 0;
        map<char, int> pattenCounter;
        for(auto i: p) {
            if (pattenCounter[i] > 0) {
                pattenCounter[i] += 1;
            } else {
                pattenCounter[i] = 1;
            }
        }
        while(right < size) {
            if (pattenCounter[s[right++]]-- >= 1) {
                pattenLength --;
            }
            if (pattenLength == 0) {
                result.push_back(left);
            }
            if (right-left == p.size() && pattenCounter[s[left++]]++ >= 0) {
                pattenLength ++;
            }
        }
        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
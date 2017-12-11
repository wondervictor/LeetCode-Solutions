#include <iostream>


using namespace std;



class Solution {
public:
    bool isSubsequence(string s, string t) {
        int tSize = (int)t.size();
        int sSize = (int)s.size();
        int tIndex = 0;
        int sIndex = 0;
        while(tIndex < tSize) {
            if (t[tIndex] == s[sIndex]) {
                sIndex ++;
                if (sIndex == sSize)
                    return true;
            }
            tIndex ++;
        }
        return sIndex == sSize;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
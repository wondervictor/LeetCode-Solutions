#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        map<char, int> pos;
        int size = (int)s.size();
        for(int i = 0; i < size; i ++) {
            if (pos.find(s[i]) != pos.end()) {
                pos[s[i]] = size;
            } else {
                pos[s[i]] = i;
            }
        }
        int index = size;
        for(map<char, int>::iterator iter = pos.begin(); iter != pos.end(); iter ++) {
            index = min(index, iter->second);
        }
        return index == size ? -1 : index;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
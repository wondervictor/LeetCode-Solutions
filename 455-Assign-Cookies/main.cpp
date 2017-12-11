#include <iostream>
#include <vector>

using std::vector;


class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        std::sort(g.begin(), g.end());
        std::sort(s.begin(), s.end());
        size_t cookieSize = s.size();
        size_t childrenSize = g.size();
        int counter = 0;
        int childIdx = 0;

        for(int i = 0; i < cookieSize;i ++) {
            if(g[childIdx] <= s[i]) {
                counter ++;
                childIdx ++;
                if(childIdx >= childrenSize)
                    break;
            }
        }
        return counter;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
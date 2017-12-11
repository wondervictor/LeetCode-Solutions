#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    struct cmp {
        bool operator() (const pair<int,int> &a, const pair<int,int> &b) {
            return a.first + a.second >= b.first + b.second;
        }

    };

    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> q1;
        vector<pair<int, int>> result;
        if (k == 0 || nums1.size() == 0 || nums2.size() == 0) {
            return result;
        }
        for(int i = 0; i < nums1.size(); i ++) {
            for(int j = 0; j < nums2.size(); j ++) {
                q1.push(pair<int,int>(nums1[i],nums2[j]));
            }
        }
        while (k > 0 && q1.size()) {
            k --;
            result.push_back(q1.top());
            q1.pop();
        }
        return result;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
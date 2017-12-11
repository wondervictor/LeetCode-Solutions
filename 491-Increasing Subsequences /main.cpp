#include <iostream>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:

    void traverse(set<vector<int> >& seqs, vector<int>& nums, int index) {
        int num = nums[index];
        set<vector<int> > newArr = seqs;
        for (auto arr: newArr) {
            if (*(arr.end()-1) <= num) {
                arr.push_back(num);
                seqs.insert(arr);
            }
        }
        if (index < nums.size()-1) {
            seqs.insert({num});
            traverse(seqs, nums, index+1);
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        if (nums.size() <= 1) {
            result.push_back(nums);
        }
        set<vector<int> > content;
        traverse(content, nums, 0);
        for(set<vector<int>>::iterator iter = content.begin(); iter != content.end();iter++) {
            if ((*iter).size() >= 2) {
                result.push_back(*iter);
            }
        }
        return result;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
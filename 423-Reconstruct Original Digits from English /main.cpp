#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    string originalDigits(string s) {

        map<char, int> count;
        for (auto i: s) {
            if (count[i] > 0) {
                count[i] += 1;
            } else {
                count[i] = 1;
            }
        }

        vector<int> nums;
        // 2 - two - w
        while(count['w'] > 0) {
            count['t'] --;
            count['w'] --;
            count['o'] --;
            nums.push_back(2);

        }
        // 4 - four - u
        while(count['u'] > 0) {
            count['f'] --;
            count['o'] --;
            count['u'] --;
            count['r'] --;
            nums.push_back(4);
        }

        // 6 - six - x
        while(count['x'] > 0) {
            count['s'] --;
            count['i'] --;
            count['x'] --;
            nums.push_back(6);
        }

        // 0 - zero - z
        while(count['z'] > 0) {
            count['z'] --;
            count['e'] --;
            count['r'] --;
            count['o'] --;
            nums.push_back(0);
        }
        // 5
        while(count['f'] > 0) {
            count['f'] --;
            count['i'] --;
            count['v'] --;
            count['e'] --;
            nums.push_back(5);
        }
        // 1
        while(count['o'] > 0) {
            count['o'] --;
            count['n'] --;
            count['e'] --;
            nums.push_back(1);
        }
        // 7
        while(count['s'] > 0) {
            count['s'] --;
            count['e'] --;
            count['v'] --;
            count['e'] --;
            count['n'] --;
            nums.push_back(7);
        }
        //9
        while(count['n'] > 0) {
            count['n'] --;
            count['i'] --;
            count['n'] --;
            count['e'] --;
            nums.push_back(9);
        }
        while(count['i'] > 0) {
            count['e'] --;
            count['i'] --;
            count['g'] --;
            count['h'] --;
            count['t'] --;
            nums.push_back(8);
        }

        while(count['e'] > 0) {
            count['t'] --;
            count['h'] --;
            count['r'] --;
            count['e'] --;
            count['e'] --;
            nums.push_back(3);
        }


        sort(nums.begin(), nums.end());
        string result;
        for(auto i: nums) {
            result.push_back((char)(i+'0'));
        }
        return result;
    }

};

int main() {

    Solution sol;
    cout<<sol.originalDigits("onetwothreeeight");



    return 0;
}
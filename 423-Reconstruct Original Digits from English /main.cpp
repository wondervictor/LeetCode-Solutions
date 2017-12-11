#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    string originalDigits1(string s) {

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

    // z 0
    // e 0 1 3 3 5 7 7 8 9
    // r 0 3 4
    // o 0 1 2 4
    // n 1 7 9 9
    // t 2 3 8
    // w 2
    // h 3 8
    // f 4 5
    // u 4
    // i 5 6 8 9
    // v 5 7
    // s 6 7
    // x 6
    // g 8

    string originalDigits(string s) {
        vector<int> nums(10,0);
        for(auto i: s) {
            switch(i) {
                case 'z': nums[0] ++;break;
                case 'w': nums[2] ++;break;
                case 'g': nums[8] ++;break;
                case 'x': nums[6] ++;break;
                case 'u': nums[4] ++;break;
                case 'i': nums[9] ++;break;
                case 'h': nums[3] ++;break;
                case 'o': nums[1] ++;break;
                case 's': nums[7] ++;break;
                case 'f': nums[5] ++;break;
                default:break;
            }
        }

        nums[3] -= nums[8];
        nums[7] -= nums[6];
        nums[5] -= nums[4];
        nums[1] -= nums[0] + nums[2] + nums[4];
        nums[9] -= nums[5] + nums[6] + nums[8];

        string result;
        for(int i = 0; i < 10; i ++) {
            cout<<nums[i]<<"\n";
            for(int j = 0; j < nums[i]; j ++) {
                result.push_back((char)(i + '0'));
            }
        }
        return result;
    }

};

int main() {

    Solution sol;
    cout<<sol.originalDigits("onetwothreeeight");



    return 0;
}
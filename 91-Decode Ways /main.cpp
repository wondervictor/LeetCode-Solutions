#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int numDecodings(string s) {
        size_t size = s.size();
        if (!size || s[0] == '0')
            return 0;
        vector<int> nums(size);
        nums[0] = 1;
        for(int i = 1; i < size; i ++) {
            nums[i] = 0;
            if (s[i] != '0') {
                nums[i] = nums[i - 1];
            }
            if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] <= '6')) {
                if (i>= 2)
                    nums[i] += nums[i - 2];
                else
                    nums[i] += 1;

            }
        }
        return nums[size-1];
    }


};


/*
 * TLE
 * ""9371597631128776948387197132267188677349946742344217846154932859125134924241649584251978418763151253""
class Solution {
public:

    int decodingWays(string s, int k) {
        int times = 0;
        if (s[k] == '0') {
            if (k == 0 || s[k-1] > '2' || s[k-1] == '0')
                return 0;
            else if (k == 1 && s[k-1] <= '2') {
                return 1;
            } else
                return decodingWays(s, k-2);
        } else {
            if (k == 0)
                return 1;
            else {
                int nums = 0;
                if (s[k-1] == '0')
                    return decodingWays(s,k-1);
                else if ((s[k-1] < '2')||(s[k-1] == '2' && s[k] <= '6')) {
                    if (k >= 2)
                        nums += decodingWays(s, k-2);
                    else
                        nums += 1;
                }
                return nums + decodingWays(s, k-1);
            }
        }
    }

    int numDecodings(string s) {
        if (!s.size())
            return 0;
        return decodingWays(s, (int)s.size()-1);
    }
};

*/

int main() {

    string s = "114235415";
    Solution sol;

    cout<<sol.numDecodings(s);

    return 0;
}
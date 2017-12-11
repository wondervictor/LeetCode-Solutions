#include <iostream>
#include <vector>

using namespace std;

// next_permutation 函数
int nextGreaterElement1(int n) {
    auto digits = to_string(n);
    next_permutation(begin(digits), end(digits));
    auto res = stoll(digits);
    return (res > INT_MAX || res <= n) ? -1 : res;
}

/*
 *
 * Failed
class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        int num = n;
        bool flag = true;
        while(num > 0) {
            int p = num%10;
            if (digits.size() > 1 && p < *(digits.end()-1)) {
                flag = false;
            }
            digits.push_back(p);
            num = num / 10;
        }
        if(flag)
            return -1;

    }
};
*/

int main() {
    int m = 31141;
    cout<<nextGreaterElement1(m)<<"\n";
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:


    int getNum(int n, vector<int>& s) {
        if (s[n] > 0)
            return s[n];
        int times = 0;
        for(int i = 1; i <= n; i ++) {
            times += (getNum(i-1, s) * getNum(n-i,s));
            cout<<i-1<<"+"<<n-i<<"\n";
        }
        cout<<"s["<<n<<"]="<<times<<"\n";
        s[n] = times;
        return times;
    }

    int numTrees(int n) {
        if (n == 0)
            return 0;
        vector<int> counter(n+1,0);
        counter[0] = 1;
        counter[1] = 1;
        counter[2] = 2;
        counter[3] = 5;
        if (n <= 3)
            return counter[n];
        return getNum(n, counter);
    }
};

int main() {

    Solution sol;

    sol.numTrees(4);
    return 0;
}
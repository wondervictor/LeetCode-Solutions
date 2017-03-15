#include <iostream>
#include <vector>
#include <stack>
using std::vector;
using std::string;
using std::stack;


class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string s = "";
        find(n,n,result,s);
        return result;
    }

    void find(int numA, int numB, vector<string> &result, string curStr) {
        if(numA > 0) {
            curStr.push_back('(');
            find(numA-1,numB, result, curStr);
            curStr.pop_back();
        }
        if(numB > 0 && numB > numA) {
            curStr.push_back(')');
            find(numA,numB-1, result, curStr);
        }
        if(numB == 0) {
            result.push_back(curStr);
        }
    }
};

using std::cout;

int main() {

    Solution sol;
    vector<string> result = sol.generateParenthesis(3);
    for(auto i: result)
        cout<<i<<std::endl;
    return 0;
}
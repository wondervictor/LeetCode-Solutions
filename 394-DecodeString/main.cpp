#include <iostream>
#include <stack>

using namespace std;




class Solution {
public:

    int decode(string& s, int fromIndex, string& currentStr) {
        int endIndex = fromIndex;
        string currentNum;
        int numValue = 0;
        for (int i = fromIndex; i < s.size(); i ++) {
            if (s[i] >= '0' && s[i] <= '9') {
                currentNum.push_back(s[i]);
            } else if (s[i] == ']') {
                endIndex = i;
                break;
            } else if (s[i] == '[') {
                numValue = atoi(currentNum.c_str());
                string currentSubString;
                int currentEndIndex = decode(s, i+1, currentSubString);
                i = currentEndIndex;
                for (int m = 0; m < numValue; m ++) {
                    currentStr.append(currentSubString);
                }
                numValue = 0;
                currentNum = "";
            } else {
                currentStr.push_back(s[i]);
            }
        }
        return endIndex;
    }

    string decodeString(string s) {
        string result;
        decode(s,0,result);
        return result;
    }
};

int main() {

    string p = "2[abc2[dqf]]3[cd]ef";
    Solution sol;
    string res = sol.decodeString(p);
    cout<<p<<"\n"<<res<<"\n";
	return 0;
}
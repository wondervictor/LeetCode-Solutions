#include <iostream>
#include <vector>

using namespace std;

class NestedInteger {
public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
    };

class Solution {
public:

    int traverse(string s, int index, NestedInteger& subNestInteger) {
        string currentStr;
        int currentNum = 0;
        int endIndex = 0;
        for (int i = index; i < s.size(); i ++) {
            if (s[i] >= '0' && s[i] <= '9') {
                currentStr.push_back(s[i]);
            } else if (s[i] == ',') {

                if (currentStr.size()) {
                    cout<<currentStr<<"\n";

                    NestedInteger num(atoi(currentStr.c_str()));
                    subNestInteger.add(num);
                    currentStr = "";
                }
            } else if (s[i] == '[') {
                int endIndx = 0;
                NestedInteger sub;
                endIndx += traverse(s, i+1, sub);
                i = endIndx;
                subNestInteger.add(sub);
            } else if (s[i] == ']') {
                if (currentStr.size()) {
                    cout<<currentStr<<"\n";
                    NestedInteger num(atoi(currentStr.c_str()));
                    subNestInteger.add(num);
                    currentStr = "";
                }
                endIndex = i;
                break;
            } else if (s[i] == '-') {
                currentStr.push_back('-');
            }

        }
        return endIndex;

    }

    NestedInteger deserialize(string s) {
        NestedInteger resultInteger;
        NestedInteger currentInteger = resultInteger;
        if (s[0] == '[') {
            traverse(s, 1, currentInteger);
        } else {
            if (s.size()) {
                currentInteger =  NestedInteger(atoi(s.c_str()));
            } else {
                currentInteger = NestedInteger(0);
            }
        }
        return currentInteger;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
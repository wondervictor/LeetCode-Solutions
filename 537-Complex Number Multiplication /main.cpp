#include <iostream>


using namespace std;


class Solution {
public:

    void getNum(string& numStr, int& real, int& imaginary) {
        string currentNum;
        for (auto i: numStr) {
            if ((i >='0' && i <= '9') || i == '-')
                currentNum.push_back(i);
            else if (i == '+') {
                real = atoi(currentNum.c_str());
                currentNum = "";
            } else if (i == 'i') {
                imaginary = atoi(currentNum.c_str());
            }
        }
    }

    string complexNumberMultiply(string a, string b) {
        int realA, imaginaryA,realB, imaginaryB;
        getNum(a,realA, imaginaryA);
//        cout<<realA<<" "<<imaginaryA<<"\n";
        getNum(b,realB, imaginaryB);

        int resReal, resImaginay;
        resReal = realA * realB - imaginaryA * imaginaryB;
        resImaginay = realA * imaginaryB + realB * imaginaryA;
        char s[20];
        sprintf(s, "%d+%di",resReal, resImaginay);
        return string(s);
    }
};

int main() {
    Solution sol;
    string s1 = "1+-1i";
    string s2 = "1+-1i";
    string s = sol.complexNumberMultiply(s1,s2);
    cout<<s1<<"\n"<<s2<<"\n"<<s<<"\n";

    return 0;
}
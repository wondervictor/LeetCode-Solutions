#include <iostream>
using std::string;
using std::cout;
using std::endl;
class Solution {
public:

    string addStrings(string num1, string num2) {
        string result;
        char s[10] = {'0','1','2','3','4','5','6','7','8','9'};
        if(num1.size() == 0)
            return num2;
        if(num2.size() == 0)
            return num1;
        int increment = 0;


        int num1Size = (int)num1.size();
        int num2Size = (int)num2.size();
        int i = num1Size-1;
        int j = num2Size-1;
        while(i >= 0 || j >= 0 || increment > 0) {
            int num = (i >= 0?num1[i]-48:0) + (j >= 0?num2[j]-48:0)+increment;
            increment = num/10;
            int re = num%10;
            string::iterator first = result.begin();
            result.insert(first,s[re]);
            j --;
            i --;
        }
        return result;
    }
};

int main() {
    string str1 = "4283561278567186517";
    string str2 = "2856127856176412751";

    Solution sol;
    string s = sol.addStrings(str1, str2);
    cout<<s<<endl;
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
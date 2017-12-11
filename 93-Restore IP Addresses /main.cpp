#include <iostream>
#include <vector>


using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        int stage = 0;
        string res;
        size_t size = s.size();
        if (size < 4)
            return result;
        for (int i = 1; i <= 3; i ++) {
            if ((i >= 2 && s[0] == '0')||(i==3 && atoi(s.substr(0, 3).c_str())>255))
                break;
            res = s.substr(0, i);
            res += '.';
            string currentStr1 = res;
            for (int j = 1; j <= 3; j ++) {
                if (j >= 2 && s[i] == '0'||(j==3 &&atoi(s.substr(i, 3).c_str())>255))
                    break;
                if (j == 3 && s[i] > '2') {
                    continue;
                }
                res = currentStr1;
                res += s.substr(i, j);
                res += '.';

                string currentStr2 = res;
                for (int k = 1; k <= 3; k ++) {
                    if (k >= 2 && s[i+j] == '0'||(k==3 && atoi(s.substr(i+j, 3).c_str())>255))
                        break;
                    if (k == 3 && s[i + j] > '2') {
                        continue;
                    }
                    res = currentStr2;
                    res += s.substr(i+j, k);
                    res += '.';

                    if (size-i-j-k > 3 || (size-i-j-k==3&&s[i+j+k] > '2'))
                        continue;
                    if ((size-i-j-k >= 2 && s[i+j+k] == '0')||(size-i-j-k==3&&atoi(s.substr(i+j+k, 3).c_str())>255))
                        continue;

                    res += s.substr(i+j+k,size-i-j-k);
                    result.push_back(res);
                    if (size-i-j-k <= 1)
                        break;
                }
                if (size-i-j <= 2)
                    break;
            }
            if (size-i <= 3)
                break;
        }
        return result;
    }
};



int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
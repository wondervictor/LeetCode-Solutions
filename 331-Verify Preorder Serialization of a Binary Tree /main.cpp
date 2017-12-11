#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:

    bool traverse(int index, vector<char>& preorder, int length, int& increment) {
        preorder[index] = '0';
        if (index+2<length && preorder[index+1] == '#' && preorder[index+2] == '#') {
            preorder[index+1] = '0';
            preorder[index+2] = '0';
            increment = 2;
            return true;
        }
        int flag = 0;
        int a = 0;
        if (index+1<length && preorder[index+1] != '#') {
            int b = 0;
            if (traverse(index+1, preorder, length,b))
                flag ++;
            a = b;
        } else if (preorder[index + 1] == '#') {
            preorder[index + 1] = '0';
            flag ++;
        }
        a += 1;
        index += a;
        if (index+1<length && preorder[index+1] != '#') {
            int b = 0;
            if (traverse(index+1, preorder, length,b))
                flag ++;
            a += b;
        } else if (preorder[index + 1] == '#') {
            preorder[index + 1] = '0';
            flag ++;
        }
        a += 1;
        increment += a;
        return flag == 2;
    }


    bool isValidSerialization(string preorder) {
        if (preorder.size() == 0) {
            return false;
        }
        if (preorder.size() == 1 && preorder[0] == '#') {
            return true;
        }
        if (preorder.size() > 1 && preorder[0] == '#') {
            return false;
        }
        vector<char> inputSeq;
        string currentStr = "";
        preorder.push_back(',');
        for(auto i: preorder) {
            if (i == '#')
                inputSeq.push_back('#');
            else if (i == ',') {
                if (currentStr.size())
                    inputSeq.push_back('1');
                currentStr = "";
            } else {
                currentStr.push_back(i);
            }
        }
        int increment = 0;
        bool flag = traverse(0, inputSeq, (int)inputSeq.size(), increment);
        for(auto i: inputSeq) {
            if (i != '0') {
                return false;
            }
        }
        return flag;
    }
};

int main() {

    string str = "9,3,4,#,#,1";
    Solution sol;
    cout<<sol.isValidSerialization(str);

    return 0;
}
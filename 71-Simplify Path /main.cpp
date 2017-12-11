#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> pathSegments;
        int state = 0;
        string currentDir;
        string dotStr;
        for (auto i: path) {
            if (state == 0) {
                if (i == '/')
                    state = 1;
            } else if (state == 1) {
                if (i == '/') {
                    state = 1;
                    if (currentDir.size())
                        pathSegments.push(currentDir);
                    currentDir = "";
                } else if (i != '.') {
                    currentDir.push_back(i);
                    state = 1;
                } else {
                    dotStr.push_back('.');
                    state = 2;
                }
            } else if (state == 2) {
                if (i == '/') {
                    state = 1;
                    dotStr = "";
                    if (currentDir.size()) {
                        currentDir.push_back('.');
                        currentDir.push_back(i);
                        pathSegments.push(currentDir);
                        currentDir = "";
                    }
                } else if (i == '.') {
                    dotStr.push_back('.');
                    state = 3;
                } else {
                    currentDir.push_back('.');
                    currentDir.push_back(i);
                    state = 1;
                    dotStr = "";
                }
            } else if (state == 3) {
                if (i == '/') {
                    dotStr = "";
                    if (pathSegments.size())
                        pathSegments.pop();
                    state = 1;
                } else if (i == '.') {
                    dotStr.push_back('.');
                    state = 4;
                } else {
                    currentDir = currentDir + dotStr + i;
                    dotStr = "";
                    state = 1;
                }
            } else if (state == 4) {
                if (i == '.') {
                    dotStr.push_back('.');
                    state = 4;
                } else if ( i == '/') {
                    pathSegments.push(dotStr);
                    dotStr = "";
                    state = 1;
                } else {
                    currentDir = currentDir + dotStr + i;
                    dotStr = "";
                    state = 1;
                }
            }
        }
        if (currentDir.size()) {
            pathSegments.push(currentDir);
        }
        if (dotStr.size() == 2) {
            if (pathSegments.size() > 0)
                pathSegments.pop();
        } else if (dotStr.size() > 2) {
            pathSegments.push(dotStr);
        }
        string result;
        while (pathSegments.size()) {
            if (pathSegments.top().size() > 0)
                result = pathSegments.top() + "/" + result;
            pathSegments.pop();
        }
        if (result.size()>1) {
            result.pop_back();
        }

        return "/" + result;
    }

};



int main() {

    Solution sol;
    string path = "\"/a/./b///../c/../././../d/..//../e/./f/./g/././//.//h///././/..///\"";
    cout<<path<<"\n";
    string m = sol.simplifyPath(path);
    cout<<m<<"\n";

    return 0;
}
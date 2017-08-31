#include <iostream>
#include <map>
#include <vector>
#include <set>
#include <math.h>

using namespace std;


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > table;
        for(auto i: strs) {
            string tmp = i;
            sort(tmp.begin(), tmp.end());
            if (table.find(tmp) == table.end()) {
                table[tmp] = vector<string>();
            }
            table[tmp].push_back(i);
        }
        vector<vector<string> > result;
        for(map<string, vector<string> >::iterator iter = table.begin(); iter != table.end(); iter ++ ) {
            result.push_back(iter->second);
        }
        return result;
    }
};


int main() {



    return 0;
}
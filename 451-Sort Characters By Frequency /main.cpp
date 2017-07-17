#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:

    int static cmp(const pair<char, int>& a, const pair<char, int>& b) {
        return a.second > b.second;
    }

    string frequencySort(string s) {
        map<char, int> counter;
        for(auto i: s) {
            if (counter[i] > 0) {
                counter[i] += 1;
            } else {
                counter[i] = 1;
            }
        }
        vector<pair<char, int> > counterVector;
        map<char, int>::iterator iter = counter.begin();
        for(; iter != counter.end(); iter ++) {
            counterVector.push_back(pair<char,int>((*iter).first, (*iter).second));
        }
        map<char,int>().swap(counter);

        sort(counterVector.begin(), counterVector.end(), cmp);
        vector<pair<char, int>>::iterator _iter = counterVector.begin();
        string result = "";
        for(; _iter != counterVector.end(); _iter ++) {
            while((*_iter).second > 0) {
                result.push_back((*_iter).first);
                (*_iter).second--;
            }
        }
        return result;
    }
};

int main() {

    Solution sol;

    cout<<sol.frequencySort("tree");
    return 0;
}
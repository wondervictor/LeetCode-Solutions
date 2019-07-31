#include <iostream>
#include <vector>
#include <map>

using namespace std;



class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
      map<char, pair<int ,int>> table;
      vector<string> results;
      if(A.size() == 0)
        return results;
      auto initStr = A[0];
      for(auto k: initStr) {
        if (table.find(k) != table.end()) {
          table[k].first += 1;
        } else {
          pair<int, int> state = make_pair(1, 0);
          table[k] = state;
        }
      }

      for(int i = 1; i < A.size(); i ++) {
        for(auto k: A[i]) {
          if(table.find(k) != table.end()) {
            table[k].second += 1;
          }
        }
        vector<char> delete_index;
        for(auto iter=table.begin(); iter != table.end(); iter ++) {
          if(iter->second.second == 0)
            delete_index.push_back(iter->first);
          else {
            iter->second.first = min(iter->second.first, iter->second.second);
            iter->second.second = 0;
          }
        }
        for(auto k: delete_index) {
          table.erase(k);
        }
      }
      for(auto qiter=table.begin(); qiter != table.end(); qiter ++) {
        string q(1, qiter->first);
        for(int i=0;i < qiter->second.first; i ++)
          results.push_back(q);
      }
      return results;
    }
};


int main() {
  std::cout << "Hello, World!" << std::endl;
  Solution sol;
  vector<string> chars{"bella","label","roller"};
  auto m = sol.commonChars(chars);
  for (auto k: m)
    cout<<k<<" ";
  return 0;
}
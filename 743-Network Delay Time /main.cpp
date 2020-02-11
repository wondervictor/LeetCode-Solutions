#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;


class Solution {
public:


    struct cmp1{
        bool operator ()(pair<int, int> &a, pair<int, int> &b){
          return a.second < b.second;
        }
    };

    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
      // vector<int> receiveTimes((size_t)N, -1);
      if(N == 1)
        return 0;

      // O(times.size())
      vector<vector<pair<int, int>>> nodes((size_t)N+1);
      for(auto tp: times) {
        nodes[tp[0]].push_back(make_pair(tp[1], tp[2]));
      }
      int maxTime = 0;
      vector<int> delay((size_t)N+1, INT_MAX);
      delay[0] = 0;
      delay[K] = 0;

      priority_queue<pair<int, int>, vector<pair<int, int>>, cmp1> edges;
      edges.push(make_pair(K, 0));
      while(edges.size()) {
        auto edge = edges.top();
        edges.pop();
        for(auto node: nodes[edge.first]) {
          int dist = node.second+edge.second;
          if(dist < delay[node.first]) {
            edges.push(make_pair(node.first, dist));
            delay[node.first] = dist;
          }
        }
      }
      for(auto t: delay) {
        if(t == INT_MAX)
          return -1;
        maxTime = max(t, maxTime);
      }
      return maxTime;
    }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    // Solution: BFS
    //
    //
    //
    //
    //
    /*
    int find(unordered_map<int, vector<pair<int, int>>>& graph, vector<int>& arrived, int src, int dst, int K) {
      if (K == 0)
        return -1;
      vector<pair<int, int>> adjs = graph[src];
      int price = -1;
      int kprice = 0;

      for(auto p: adjs) {
        kprice = 0;
        if (p.first != dst) {
          if (arrived[p.first] == -2) {
            find(graph, arrived, p.first, dst, K-1);
          }
          kprice = arrived[p.first];
        }
        if (kprice == -1)
          continue;
        kprice = p.second + kprice;
        price = price == -1 ? kprice : price;
        price = price > kprice ? kprice : price;
      }

      if (arrived[src] == -2)
        arrived[src] = price;
      else
        arrived[src] = price > arrived[src] ? arrived[src] : price;
      return arrived[src];
    }
    */

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
      unordered_map<int, vector<pair<int, int>>> graph;
      for(auto f: flights) {
        auto& p = graph[f[0]];
        p.emplace_back(make_pair(f[1], f[2]));
      }
      queue<pair<int, int>> nexts;
      nexts.push(make_pair(src, 0));
      int minPrice = INT_MAX;
      int m = 0;

      while (!nexts.empty()) {
        auto size = nexts.size();
        for(auto i = 0; i<size; i++) {
          auto t = nexts.front();
          nexts.pop();

          if (t.first == dst)
            minPrice = min(minPrice, t.second);

          for(auto& p: graph[t.first]) {
            if (p.second + t.second > minPrice) continue;
            nexts.push(make_pair(p.first, p.second + t.second));
          }
        }
        if (m++ > K)
          break;
      }
      return minPrice == INT_MAX ? -1 : minPrice;
    }
};

int main() {
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
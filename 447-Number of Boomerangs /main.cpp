#include <iostream>
#include <vector>
#include <map>
using namespace std;


class Solution {
public:
    int distance(pair<int, int>& a, pair<int, int>& b) {
        return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
    }

    int numberOfBoomerangs(vector<pair<int, int>>& points) {
//        map<int, int> distances;

        size_t size = points.size();
        int num = 0;
        for (int i = 0; i < size; i ++) {
            map<int, int> distances;
            for (int j = 0; j < size; j ++ ) {
                int dist = distance(points[i], points[j]);
                distances[dist] += 1;
            }
            map<int, int>::iterator iter = distances.begin();
            for (; iter != distances.end(); iter ++) {
                if (iter->second>1) {
                    num += iter->second * (iter->second-1);
                    //num += iter->second-1;
                }
            }
        }
        return num;

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
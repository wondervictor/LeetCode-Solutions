#include <iostream>
#include <map>
#include <vector>
#include <queue>


using namespace std;



class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        map<int, vector<int> > edges;
        vector<int> inNodeNums(numCourses, 0);
        for(auto i: prerequisites) {
            if (edges[i.second].size()==0) {
                vector<int> s = {i.first};
                edges[i.second] = s;
            } else {
                edges[i.second].push_back(i.first);
            }
            if (!inNodeNums[i.first]) {
                inNodeNums[i.first] = 1;
            } else {
                inNodeNums[i.first] += 1;
            }

            if (!inNodeNums[i.second]) {
                inNodeNums[i.second] = 0;
            }
        }
        queue<int> nodes;
        vector<int> result;

        int leftNodeNum = numCourses;
        for (int i = 0; i < numCourses; i ++) {
            if (inNodeNums[i] == 0) {
                nodes.push(i);
            }
        }

        while (nodes.size()) {
            int i = nodes.front();
            nodes.pop();
            vector<int> subEdges = edges[i];
            for(auto m: subEdges) {
                inNodeNums[m] -= 1;
                if (inNodeNums[m] == 0) {
                    nodes.push(m);
                }
            }
            result.push_back(i);
            vector<int>().swap(edges[i]);
            numCourses --;
        }

        if (numCourses > 0) {
            vector<int>().swap(result);
        }
        return result;
    }
};




int main() {




    return 0;
}
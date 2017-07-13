#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;



class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        map<int, vector<int> > edges;
        vector<int> inNodeNums(numCourses, 0);
        for(auto i: prerequisites) {
            if (edges[i.first].size()==0) {
                vector<int> s = {i.second};
                edges[i.first] = s;
            } else {
                edges[i.first].push_back(i.second);
            }
            if (!inNodeNums[i.second]) {
                inNodeNums[i.second] = 1;
            } else {
                inNodeNums[i.second] += 1;
            }
            if (!inNodeNums[i.first]) {
                inNodeNums[i.first] = 0;
            }
        }
        queue<int> nodes;
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
            vector<int>().swap(edges[i]);
            numCourses --;
        }

        return numCourses == 0;
    }
};

int main() {

    vector<pair<int, int> > m = {pair<int,int>(0,1), pair<int,int>(1,2), pair<int,int>(2,3), pair<int,int>(3,4), pair<int,int>(4,3)};

    Solution sol;
    cout<<sol.canFinish(5, m);

    return 0;
}
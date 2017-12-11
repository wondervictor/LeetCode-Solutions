#include <iostream>
#include <vector>
#include <map>
using namespace std;



class Solution {
public:

    double search(map<string, map<string, double > >& graph, string a, string b, map<string, int>& visited,double currentValue) {
        if (graph[a][b]) {
            return graph[a][b]*currentValue;
        } else {
            visited[a] = 1;
            map<string, double > subMap = graph[a];
            map<string, double >::iterator iter = subMap.begin();
            for(;iter != subMap.end(); iter ++) {
                if (visited[iter->first] || graph[a][b] == 0 ) {
                    continue;
                }
                double value = search(graph,iter->first, b, visited,currentValue*graph[a][iter->first]);
                if (value != -1)
                    return value;
            }
            return -1;
        }
    }

    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        map<string, map<string, double > > graph;
        int size = (int)equations.size();
        for(int i = 0; i < size; i ++) {
            double value = values[i];
            pair<string, string> equation = equations[i];
            map<string, double >& sub1 = graph[equation.first];
            sub1[equation.second] = value;
            map<string, double >& sub2 = graph[equation.second];
            sub2[equation.first] = 1.0/value;
        }
        vector<double> result;
        for(auto p: queries) {
            if (graph[p.first].size() && p.first == p.second) {
                result.push_back(1);
            } else {
                map<string, int> visted;
                result.push_back(search(graph, p.first, p.second, visted,1.0));
            }
        }

        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
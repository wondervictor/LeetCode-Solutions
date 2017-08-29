#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    // O(N^2)
    int canCompleteCircuit1(vector<int> &gas, vector<int> &cost) {

        size_t size = cost.size();
        vector<int> netGas(size);
        int gasSum = 0, costSum = 0;

        for (int i = 0; i < size; i++) {
            netGas[i] = gas[i] - cost[i];
            gasSum += gas[i];
            costSum += cost[i];
        }

        if (gasSum < costSum)
            return -1;

        int start = 0;

        int currentGas = 0;
        for (int i = 0; i < size; i++) {
            if (netGas[i] < 0)
                continue;
            currentGas = netGas[i];
            bool can = true;
            for (int j = 1; j < size; j++) {
                int index = j + i >= size ? j + i - (int) size : j + i;
                currentGas += netGas[index];
                if (currentGas < 0) {
                    can = false;
                    break;
                }

            }
            if (can)
                return i;
        }
        return -1;
    }

    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int left = 0, right = 0;
        int sum = 0;

    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
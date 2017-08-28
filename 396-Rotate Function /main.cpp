#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
    int maxRotateFunction(vector<int>& A) {

        int sum = 0;
        int size = (int)A.size();

        if (!size)
            return 0;

        int rawSum = 0;
        for(int i = 0; i < size; i ++) {
           sum += i * A[i];
            rawSum += A[i];
        }

        int maxSum = sum;

        for(int i = size-1; i >= 0; i --) {
            sum += rawSum;
            sum -= size*A[i];

            if (sum > maxSum)
                maxSum = sum;
        }
        return maxSum;
    }
};




int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:


    void search(vector<int>& seqs, int num, int n) {
        if (num > n)
            return;
        seqs.push_back(num);
        for(int i = 0; i <= 9; i ++) {
            search(seqs, num*10+i,n);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> numbers;
        if (n <= 0)
            return numbers;
        for(int i = 1; i < 10; i ++) {
            search(numbers, i, n);
        }
        return numbers;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
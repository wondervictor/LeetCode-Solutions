#include <iostream>
#include <vector>


using std::vector;
using std::string;

class Solution {
public:

    vector<string> fizzBuzz(int n) {
        vector<string> result;
        for (int i = 1; i <= n; ++i) {
            string s = "";
            if(i % 3 == 0)
                s = "Fizz";
            if(i % 5 == 0)
                s.append("Buzz");
            if(i%3 != 0 && i%5 != 0) {
                char a[20];
                sprintf(a,"%d",i);
                s = a;
            }
            result.push_back(s);
        }
        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
#include <iostream>
#include <vector>

using std::vector;



class Solution {
public:

    // Dirty Method
//    void sortColors(vector<int>& nums) {
//        int red = 0, white = 0, blue = 0;
//        for(auto i: nums) {
//            if(i == 0)
//                red ++;
//            else if(i == 1)
//                white ++;
//            else
//                blue ++;
//        }
//        int counter = 1;
//        for(auto &i: nums) {
//            if(counter <= red)
//                i = 0;
//            else if(counter <= red+white)
//                i = 1;
//            else
//                i = 2;
//            counter ++;
//        }
//    }
    void sortColors(vector<int>& nums){

    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
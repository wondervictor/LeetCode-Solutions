#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
  string toHex(int num) {
    if (num == 0)
      return "0";
    string result = "";
    vector<string> maps = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f"};
    int tmp = 0;
    for (int i = 0; i < 8 && num != 0; i++) {
      tmp = num >> 4;
      result = maps[num-tmp*16] + result;
      num = tmp;
    }
    return result;
  }

//    int a[8] = {0};
//    for(int i = 0; i < 8 && num != 0; i ++) {
//      int tmp = num >> 4;
//      a[7-i] = num - tmp*16;
//      num = tmp;
//    }
//    int index = 0;
//    while(a[index] == 0) {
//      index ++;
//    }
//    for(int i = index; i < 8; i ++) {
//      result.push_back(maps[a[i]]);
//    }
//    return result;
//  }
};



int main() {
  int a = 10;
  Solution sol;
  cout<<sol.toHex(10)<<endl<<sol.toHex(23)<<endl<<sol.toHex(-1);

  return 0;
}
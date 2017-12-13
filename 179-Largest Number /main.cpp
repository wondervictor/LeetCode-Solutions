#include <iostream>
#include <vector>
#include <sstream>

using namespace std;



//others

struct {
  bool operator()(string a, string b)
  {
    string c1 = a + b;
    string c2 = b + a;
    return c1 > c2;
  }
} compareDigits;


class Solution {
 public:
  string largestNumber(vector<int> &num) {
    if (num.size() == 0) return "";
    vector<string> num_str;
    for (int i = 0; i < num.size(); ++i) {
      num_str.push_back(to_string(num[i]));
    }
    std::sort(num_str.begin(), num_str.end(), compareDigits);
    string res1 = "";
    for (int i = 0; i < num_str.size(); ++i)
      res1 += num_str[i];
    if (res1[0] == '0')
      return "0";
    else
      return res1;
  }
};



// Stupid
class Solution {
public:

    static int compare(const int& a, const int& b) {
      if (a == 0 || b == 0) {
        return  a > b;
      }
      vector<int> aNums;
      vector<int> bNums;
      int aCopy = a;
      int bCopy = b;
      while(aCopy > 0) {
        aNums.push_back(aCopy % 10);
        aCopy = aCopy / 10;
      }
      while(bCopy > 0) {
        bNums.push_back(bCopy%10);
        bCopy = bCopy / 10;
      }

      int aSize = (int)aNums.size();
      int bSize = (int)bNums.size();
      while(aSize > 0 && bSize > 0) {
        if (aNums[aSize-1] != bNums[bSize-1]) {
          return aNums[aSize-1] > bNums[bSize-1];
        }
        aSize --;
        bSize --;
      }
      if (aSize > 0) {
        return aNums[aSize-1] >= bNums[0] && aNums[aSize-1] >= *(bNums.end()-1);
      }
      if (bSize > 0) {
        return aNums[0] >= bNums[bSize-1] && *(aNums.end()-1) > bNums[bSize-1];
      }
      return 1;
    }
    string largestNumber(vector<int>& nums) {
      sort(nums.begin(), nums.end(), compare);
      string s;
      int flag = 0;
      if (nums[0] == 0 ) {
        s = "0";
        return s;
      }
      for(auto i: nums) {
        cout<<i<<" ";
        stringstream ss;
        ss<<i;
        s += ss.str();
      }
      return s;
    }
};

/**
 * 98909827968595339456944893859149094902689398937839883538183810810780707982784676057536747174237321720571007032685668066758674466986636554651163276306626562416221603859725909578457125682552954605422520849804812479847044453428339323905384638363699366436503636357535673516346233993298316330843021297028227452732697246523622362231322281216213206020001921763154815181495141713801147114310901048
 * 98909827968595339456944893859149094902689398937839883538183810810780707982784676057536747174237321720571007032685668066758674466986636554651163276306626562416221603859725909578457125682552954605422520849804812479847044453428339323905384638363699366436503636357535673516346233993298316330843021297028227452732697246523622362231322812216213206020001921763154815181495141713801147114310901048"

 *
 * */


int main() {
  vector<int> nums = {121,12,122,1222,1212, 1211, 1};
  Solution sol;
  string s = sol.largestNumber(nums);
  cout<<s;
  //std::cout << "Hello, World!" << std::endl;
  return 0;
}
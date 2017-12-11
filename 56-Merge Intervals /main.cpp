#include <iostream>
#include <vector>

using namespace std;


//Definition for an interval.
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};




class Solution {
public:

    static int cmp(const Interval& a, const Interval& b) {
        return a.start < b.start;
    }

    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if (intervals.size() == 0) {
            return result;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        Interval currentInterval = intervals[0];
        for(auto inter: intervals) {
            if (inter.start > currentInterval.end) {
                result.push_back(currentInterval);
                currentInterval = inter;
            } else if (inter.start <= currentInterval.end) {
                if (inter.end > currentInterval.end) {
                    currentInterval.end = inter.end;
                }
            }
        }
        result.push_back(currentInterval);
        return result;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
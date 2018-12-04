#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <set>


using namespace std;


class ExamRoom {

public:
    ExamRoom(int N):numSeats(N) {}

    int seat() {
      int result = 0;
      if (!seats.empty()) {
        int idx = 0;
        int maxLen = 0;
        if (!seats.count(0)) {
          result = 0;
          maxLen = *seats.begin();
        }
        for(auto iter=seats.begin(); iter != seats.end(); iter++) {
          int len = (*iter - idx)/2;
          if (len > maxLen) {
            result = (*iter+idx)/2;
            maxLen = len;
          }
          idx = *iter;
        }
        if (!seats.count(numSeats-1)) {
          if (numSeats-1-*seats.rbegin() > maxLen)
            result = numSeats-1;
        }

      }
      seats.insert(result);
      return result;
    }

    void leave(int p) {
      seats.erase(p);
    }

private:
    set<int> seats;
    int numSeats;

};



// Merge and Split with priority queue
class ExamRoom1 {

public:

    static int effectiveDistance(vector<int> a) {
      // effective max distance
      if (a[2] && a[3])
        return (a[1]-a[0])/2;
      if (a[2] || a[3])
        return a[1]-a[0];
      else
        return a[1]-a[0]+1;
    }


    static int getSeatLocation(vector<int> a) {
      if (a[2] && a[3])
        return (a[1] + a[0])/2;
      if (!a[2])
        return a[0];
      else
        return a[1];
    }

    struct cmp {
        bool operator()(vector<int> &a, vector<int> &b) const {
          int effectiveDistA = effectiveDistance(a);
          int effectiveDistB = effectiveDistance(b);

//          std::cout<<"a:";
//          for(auto i: a)
//            std::cout<<i<<" ";
//          std::cout<<" "<<effectiveDistA<<"\n";
//
//          std::cout<<"b:";
//          for(auto i: b)
//            std::cout<<i<<" ";
//          std::cout<<" "<<effectiveDistB<<"\n";
//          std::cout<<"---"<<endl;

          if (effectiveDistA > effectiveDistB)
            return false;
          else if (effectiveDistA < effectiveDistB)
            return true;
          else {
            // cout<<"a:"<<getSeatLocation(a)<<" b:"<<getSeatLocation(b)<<endl;
            return getSeatLocation(a) > getSeatLocation(b);
          }
        }
    };

    ExamRoom1(int N) {
      vector<int> a = {0, N-1, 0, 0};
      all = N-1;
      seats.push(a);
    }

    int seat() {
      auto topSeat = seats.top();
//      for(auto i: seats.top())
//        std::cout<<i<<" ";
//      std::cout<<"\n--\n";
      seats.pop();
      int location = getSeatLocation(topSeat);
      split(topSeat, location);

      return location;
    }

    void split(vector<int> &curSeat, int location) {
      if (!curSeat[2]){
        curSeat[2] = 1;
        seats.push(curSeat);
        return;
      }
      if (!curSeat[3]) {
        curSeat[3] = 1;
        seats.push(curSeat);
        return;
      }

      vector<int> a = {curSeat[0], location, 1, 1};
      vector<int> b = {location, curSeat[1], 1, 1};
      seats.push(a);
      seats.push(b);
    }

    void leave(int p) {
      int startLocation = -1, startFlag=0;
      int endLocation = -1, endFlag=0;

      if (p==0) {
        startLocation = 0;
        startFlag = 0;
      }
      if (p == all) {
        endLocation=all;
        endFlag = 0;
      }

      vector<vector<int>> tmp;
      while (!seats.empty() && (startLocation == -1||endLocation == -1)) {
        auto a = seats.top();
        seats.pop();
        if (a[0] == p) {
          endLocation = a[1];
          endFlag = a[3];
        } else if (a[1] == p) {
          startLocation = a[0];
          startFlag = a[2];
        } else {
          tmp.push_back(a);
        }
      }

      vector<int> a = {startLocation, endLocation, startFlag, endFlag};
      seats.push(a);
      vector<vector<int>>::iterator iter;
      for(iter=tmp.begin(); iter != tmp.end(); iter ++) {
        seats.push(*iter);
      }
    }
private:
    priority_queue<vector<int>, vector<vector<int>>, cmp> seats;
    int all;

};


int main() {
  ExamRoom examRoom(4);
  std::cout<<examRoom.seat()<<"|\n";
  std::cout<<examRoom.seat()<<"|\n";
  std::cout<<examRoom.seat()<<"|\n";
  std::cout<<examRoom.seat()<<"|\n";
  examRoom.leave(1);
  examRoom.leave(3);
  std::cout<<examRoom.seat()<<"|\n";
  std::cout<<examRoom.seat()<<"|\n";
  std::cout << "Hello, World!" << std::endl;
  return 0;
}
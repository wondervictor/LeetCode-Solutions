#include <iostream>
#include <vector>
#include <queue>
#include <map>


using namespace std;

class Solution {
public:



    bool checkBorder(int i, int j, size_t x, size_t y) {
        if (i == 0 || i == x - 1 || j == 0 || j == y - 1)
            return true;
        else
            return false;
    }

    void search(vector<vector<char>>& board, int i, int j, size_t x, size_t y) {
//        vector<pair<int, int> > points;
//        bool flag = false;
        queue<pair<int, int> > pointQueues;
        //visted[i][j] = 1;
        pointQueues.push(make_pair(i,j));
        while(pointQueues.size()) {
            size_t queueSize = pointQueues.size();
            for(int m = 0; m < queueSize; m ++) {
                auto point = pointQueues.front();
                pointQueues.pop();
                board[point.first][point.second] = '1';
//                if (checkBorder(point.first, point.second, x, y))
//                    flag = true;
                if (point.first > 0 && board[point.first-1][point.second] == 'O')
                    pointQueues.push(make_pair(point.first-1,point.second));
                if (point.second > 0 && board[point.first][point.second-1] == 'O')
                    pointQueues.push(make_pair(point.first,point.second-1));
                if (point.first < x-1 && board[point.first+1][point.second] == 'O')
                    pointQueues.push(make_pair(point.first+1,point.second));
                if (point.first < y-1 && board[point.first][point.second+1] == 'O')
                    pointQueues.push(make_pair(point.first,point.second+1));
            }
        }
//        if (!flag) {
//            for (pair<int, int> p: points) {
//                board[p.first][p.second] = 'X';
//            }
//        } else {
//            for (pair<int, int> p: points) {
//                board[p.first][p.second] = 'O';
//            }
//        }
    }

    void check(vector<vector<char>>& board, int i, int j, size_t x, size_t y) {
        if (board[i][j] != 'O')
            return;
        board[i][j] = '1';
        if (i > 0)
            check(board,i-1,j,x,y);
        if (j > 0)
            check(board,i,j-1,x,y);
        if (i < x-1)
            check(board,i+1,j,x,y);
        if (j < y-1)
            check(board,i,j+1,x,y);
    }

    void solve(vector<vector<char>>& board) {
        size_t x = board.size();
        if (x == 0) {
            return;
        }
        size_t y = board[0].size();
        for (int i = 0; i < x-1; i ++) {
            check(board,i,0,x,y);
            if (y > 1)
                check(board,i,y-1,x,y);

        }
        for (int i = 1; i < y-1; i ++) {
            check(board,0,i,x,y);
            if ( x > 1)
                check(board,x-1,i,x,y);

        }
        for (int i = 0; i < x; i ++) {
            for (int j = 0; j < y; j ++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] =='1')
                    board[i][j] = 'O';
            }
        }

//        map<pair<int, int>,int> visited;
//        for (int i = 0; i < x; i ++) {
//            for (int j = 0; j < y; j ++) {
//                if (board[i][j] == 'O') {
//                    search(board,i,j,x,y);
//                }
//            }
//        }
    }
};


int main() {

    Solution sol;
    vector<char> s1 = {'X','O','X','O','X'};
    vector<char> s2 = {'O','X','O','X','O'};
    vector<char> s3 = {'X','O','X','O','X'};
    vector<char> s4 = {'O','X','O','X','O'};

    vector<vector<char> > s;
    s.push_back(s1);
    s.push_back(s1);
    s.push_back(s1);
    s.push_back(s2);

    sol.solve(s);


    return 0;
}
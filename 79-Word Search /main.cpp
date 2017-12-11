#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    bool traverse(vector<vector<char> >& board, vector<vector<int> >& flags, string& word, int currentIndex, int x, int y) {
        bool flag = false;
        if (flags[x][y] == 1)
            return false;
        if (board[x][y] ==word[currentIndex]) {
            if (currentIndex + 1 == word.size()) {
                return true;
            }
            flags[x][y] = 1;
            if (x < board.size()-1) {
                flag = flag || traverse(board, flags, word, currentIndex+1, x+1,y);
            }
            if (board.size() && y < board[0].size()-1) {
                flag = flag || traverse(board, flags, word, currentIndex+1, x,y+1);
            }
            if (x > 0) {
                flag = flag || traverse(board, flags, word, currentIndex+1, x-1,y);
            }
            if (y > 0) {
                flag = flag || traverse(board, flags, word, currentIndex+1, x,y-1);
            }
            flags[x][y] = 0;
            return flag;
        } else {
            return false;
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        size_t a = board.size();
        if (a == 0)
            return false;
        size_t b = board[0].size();

        vector<vector<int> > flags(a, vector<int>(b));
        for(int i = 0; i < board.size(); i ++) {
            for (int j = 0; j < board[i].size(); j ++) {
                if (traverse(board,flags,word,0,i,j))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    vector<char> a = {'A','B','C','E'};
    vector<char> b = {'S','F','C','S'};
    vector<char> c = {'A','D','E','E'};


    //string b = "SFCS";
    //string c = "ADEE";
    vector<vector<char> > s={a,b,c};

    Solution sol;
    cout<<sol.exist(s,"ABCCED");


    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

class Solution {
public:

    // wrong
    int leastInterval1(vector<char>& tasks, int n) {
        size_t size = tasks.size();
        if (size == 0) {
            return 0;
        }
        if (n == 1 || n == 0) {
            return (int)size;
        }
//        queue<char> taskQueue;
        map<char, int> taskNums;
        for(auto i: tasks) {
            if (taskNums[i] > 0) {
                taskNums[i] += 1;
            } else {
                taskNums[i] = 1;
            }
        }
        int nums = (int)size;
        int pSize = nums;
        vector<char> taskQueue;
        queue<char> dealQueue;
        while(size > 0) {
            map<char, int>::iterator iter = taskNums.begin();
            for(; iter != taskNums.end(); iter ++) {
                if (iter->second > 0) {
                    iter->second --;
                    taskQueue.push_back(iter->first);
                    size --;
                }
            }
        }

        //test
        vector<char> ps;


        for (int i = 0; i < pSize;) {
            if (dealQueue.size() < n) {
                int distance = n+1;
                if (taskNums[taskQueue[i]] > 0) {
                    distance = i - taskNums[taskQueue[i]];
                }
                while(taskNums[taskQueue[i]] > 0) {
                    char p = dealQueue.front();
                    dealQueue.pop();
                    if (p != '0') {
                        taskNums[p] = 0;
                    }
                    nums ++;
                    dealQueue.push('0');
                    ps.push_back('0');
                    distance ++;
                }
                if (distance < n) {
                    while(distance < n) {
                        if (dealQueue.size() == n) {
                            char p = dealQueue.front();
                            dealQueue.pop();
                            if (p != '0') {
                                taskNums[p] = 0;
                            }
                            nums ++;
                            dealQueue.push('0');
                            ps.push_back('0');
                            distance ++;
                        } else {
                            distance ++;
                            dealQueue.push('0');
                            ps.push_back('0');
                            nums ++;
                        }

                    }
                    continue;
                } else {
                    taskNums[taskQueue[i]] = 1+i;
                    dealQueue.push(taskQueue[i]);
                    ps.push_back(taskQueue[i]);
                    i ++;
                }
            } else if (dealQueue.size() == n){
                while(taskNums[taskQueue[i]] > 0) {
                    char p = dealQueue.front();
                    dealQueue.pop();
                    if (p != '0') {
                        taskNums[p] = 0;
                    }
                    nums ++;
                    dealQueue.push('0');
                    ps.push_back('0');
                }
                char p = dealQueue.front();
                dealQueue.pop();
                if (p != '0') {
                    taskNums[p] = 0;
                }
                taskNums[taskQueue[i]] = 1+i;
                dealQueue.push(taskQueue[i]);
                ps.push_back(taskQueue[i]);
                i ++;
            }
        }
        for(auto i: ps) {
            cout<<i<<" ";
        }
        cout<<"\n";

        return nums;
    }

    class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
            map<char, int> m;
            for (int i = 0; i < tasks.size(); ++i) {
                m[tasks[i]]++;
            }
            priority_queue<int> pq;
            for (auto ite : m){
                pq.push(ite.second);
            }
            int cycle = n + 1, ret = 0;
            while(!pq.empty()){
                vector<int> tmp;
                int time = 0;
                for (int i = 0; i < cycle; ++i) {
                    if (!pq.empty()){
                        tmp.push_back(pq.top());
                        pq.pop();
                        time++;
                    }
                }

                for (auto cnt : tmp){
                    int remainCnt = cnt - 1;
                    if(remainCnt > 0)pq.push(remainCnt);
                }
                if(pq.empty()) ret += time;//如果是最后一次调度，不在需要idle来填充
                else ret += cycle;
            }
            return ret;
        }
    };
};




int main() {

    vector<char> s = {'A','A','A','A','A','A','B','C','D','E','F','G'};
    Solution sol;

    cout<<"\n"<<sol.leastInterval(s,2);

    return 0;
}
#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;


class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        this->userTable = map<int, set<int>>();
        this->tweetSize = 0;
        this->tweets = vector<pair<int, int> >();
    }

    void checkUser(int userId) {
        if (this->userTable.find(userId) == this->userTable.end()) {
            set<int>* newSet = new set<int>();
            this->userTable[userId] = *newSet;
        }
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        checkUser(userId);
        tweetSize ++;
        this->tweets.push_back(pair<int, int>(userId, tweetId));
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        checkUser(userId);
        set<int> followedUsers = userTable[userId];
        followedUsers.insert(userId);
        vector<int> feeds;
        int index = tweetSize-1;
        int counter = 0;
        while(counter < 10 && index >= 0) {
            pair<int, int> tmpTweet = tweets[index];
            if (followedUsers.find(tmpTweet.first) != followedUsers.end()) {
                feeds.push_back(tmpTweet.second);
                counter ++;
            }
            index--;
        }
        return feeds;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        checkUser(followeeId);
        checkUser(followerId);
        this->userTable[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        this->userTable[followerId].erase(followeeId);
    }

private:

    map<int, set<int>> userTable;
    vector<pair<int, int> > tweets;
    int tweetSize;

};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */

int main() {

    Twitter* obj = new Twitter();
    obj->postTweet(1,5);
    vector<int> wee = obj->getNewsFeed(1);
    for(auto i: wee)
        cout<<i<<" ";



    return 0;
}
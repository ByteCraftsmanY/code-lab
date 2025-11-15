// Design twitter
// Step: Heaps [Learning, Medium, Hard Problems]
// Sub Step: Hard Problems
// Post Link: https://takeuforward.org/data-structure/design-twitter
// LeetCode Link: https://leetcode.com/problems/design-twitter/

#include <bits/stdc++.h>
using namespace std;

class Tweet {
   public:
    int tweetId;
    int timestamp;
    Tweet* next;
    Tweet(int tweetId, int timestamp, Tweet* next) : tweetId(tweetId), timestamp(timestamp), next(next) {}
};

class Compare {
   public:
    bool operator()(Tweet* a, Tweet* b) {
        return a->timestamp < b->timestamp;
    }
};

class Twitter {
   private:
    int count = 0;
    unordered_map<int, unordered_set<int>> userFollowers;
    unordered_map<int, Tweet*> userTweets;

   public:
    Twitter() {
    }

    void postTweet(int userId, int tweetId) {
        Tweet* userTweet = this->userTweets[userId];
        this->userTweets[userId] = new Tweet(tweetId, this->count, userTweet);
        this->count++;
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<Tweet*, vector<Tweet*>, Compare> pq;
        Tweet* tweet = nullptr;
        this->userFollowers[userId].insert(userId);
        for (auto followerId : this->userFollowers[userId]) {
            tweet = this->userTweets[followerId];
            if (tweet) pq.push(tweet);
        }

        vector<int> result;
        int maxPosts = 10;
        while (maxPosts && !pq.empty()) {
            tweet = pq.top();
            pq.pop();
            result.push_back(tweet->tweetId);
            tweet = tweet->next;
            if (tweet) pq.push(tweet);
            maxPosts--;
        }
        return result;
    }

    void follow(int followerId, int followeeId) {
        unordered_set<int> st = this->userFollowers[followerId];
        st.insert(followeeId);
        this->userFollowers[followerId] = st;
    }

    void unfollow(int followerId, int followeeId) {
        unordered_set<int> st = this->userFollowers[followerId];
        auto it = st.find(followeeId);
        if (it != st.end()) {
            st.erase(it);
        }
        this->userFollowers[followerId] = st;
    }
};

int main() {
    // INSERT_YOUR_CODE
    // Example 1: Basic usage
    Twitter twitter;

    // User 1 posts a tweet (id = 5)
    twitter.postTweet(1, 5);

    // User 1's news feed should return a list with 1 tweet id -> [5]
    vector<int> feed1 = twitter.getNewsFeed(1);
    cout << "Feed for user 1: ";
    for (int id : feed1) cout << id << " ";
    cout << endl;

    // User 1 follows user 2
    twitter.follow(1, 2);

    // User 2 posts a tweet (id = 6)
    twitter.postTweet(2, 6);

    // User 1's news feed should return [6, 5]
    feed1 = twitter.getNewsFeed(1);
    cout << "Feed for user 1 after following 2 and 2 posts: ";
    for (int id : feed1) cout << id << " ";
    cout << endl;

    // User 1 unfollows user 2
    twitter.unfollow(1, 2);

    // User 1's news feed should return [5]
    feed1 = twitter.getNewsFeed(1);
    cout << "Feed for user 1 after unfollowing 2: ";
    for (int id : feed1) cout << id << " ";
    cout << endl;

    // Additional: Multiple tweets per user
    twitter.postTweet(1, 17);
    twitter.postTweet(1, 22);
    twitter.postTweet(2, 34);
    twitter.follow(1, 2);

    feed1 = twitter.getNewsFeed(1);
    cout << "Feed for user 1 after additional posts: ";
    for (int id : feed1) cout << id << " ";
    cout << endl;

    return 0;
}

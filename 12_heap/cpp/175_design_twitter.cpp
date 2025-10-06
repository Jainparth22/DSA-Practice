// LC#355 — Design Twitter
// Difficulty: Medium | Pattern: Heap merge of feeds | Time: O(F log F) feed | Space: O(users + tweets)
#include <bits/stdc++.h>
using namespace std;
class Twitter {
    int time = 0; unordered_map<int, vector<pair<int,int>>> tweets; unordered_map<int, unordered_set<int>> follows;
public:
    void postTweet(int u, int t) { tweets[u].push_back({time++, t}); }
    vector<int> getNewsFeed(int u) {
        priority_queue<pair<int,int>> pq; follows[u].insert(u);
        for (int f : follows[u]) { auto& v = tweets[f]; for (int i = max(0, (int)v.size() - 10); i < (int)v.size(); i++) pq.push(v[i]); }
        vector<int> res; while (!pq.empty() && res.size() < 10) { res.push_back(pq.top().second); pq.pop(); }
        return res;
    }
    void follow(int a, int b) { follows[a].insert(b); }
    void unfollow(int a, int b) { if (a != b) follows[a].erase(b); }
};
int main() { Twitter t; t.postTweet(1, 5); t.follow(2, 1); cout << t.getNewsFeed(2)[0] << endl; } // 5

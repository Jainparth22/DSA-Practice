# LC#355 — Design Twitter
# Difficulty: Medium | Pattern: Heap merge of feeds | Time: O(F log F) feed | Space: O(users + tweets)
import heapq
from collections import defaultdict

class Twitter:
    def __init__(self): self.time = 0; self.tweets = defaultdict(list); self.follows = defaultdict(set)
    def post_tweet(self, u, t): self.tweets[u].append((self.time, t)); self.time += 1
    def get_news_feed(self, u):
        users = self.follows[u] | {u}
        return [t for _, t in heapq.nlargest(10, (x for f in users for x in self.tweets[f][-10:]))]
    def follow(self, a, b): self.follows[a].add(b)
    def unfollow(self, a, b): self.follows[a].discard(b)

t = Twitter(); t.post_tweet(1, 5); t.follow(2, 1); assert t.get_news_feed(2) == [5]; t.unfollow(2, 1); assert t.get_news_feed(2) == []

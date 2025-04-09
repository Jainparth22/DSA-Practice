# LC#146 — LRU Cache
# Difficulty: Medium
# Pattern: OrderedDict (or Hash Map + Doubly Linked List)
# Time: O(1) for get and put | Space: O(capacity)
#
# Approach (using OrderedDict):
#   Python's OrderedDict preserves insertion order and supports move_to_end().
#   Most-recently-used at the END, least-recently-used at the START.
#   get: move accessed key to end, return value or -1.
#   put: update/insert key, move to end, evict from start if over capacity.

from collections import OrderedDict


class LRUCache:
    def __init__(self, capacity: int):
        self.cap = capacity
        self.cache = OrderedDict()

    def get(self, key: int) -> int:
        if key not in self.cache:
            return -1
        self.cache.move_to_end(key)   # mark as most recently used
        return self.cache[key]

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.cache.move_to_end(key)
        self.cache[key] = value
        if len(self.cache) > self.cap:
            self.cache.popitem(last=False)  # evict LRU (from start)


if __name__ == "__main__":
    lru = LRUCache(2)
    lru.put(1, 1)
    lru.put(2, 2)
    assert lru.get(1) == 1       # 1 accessed → MRU
    lru.put(3, 3)                # evicts key 2
    assert lru.get(2) == -1      # evicted
    lru.put(4, 4)                # evicts key 1
    assert lru.get(1) == -1      # evicted
    assert lru.get(3) == 3
    assert lru.get(4) == 4
    print("All tests passed!")

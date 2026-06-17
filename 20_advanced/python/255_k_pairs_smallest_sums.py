# LC#373 — Find K Pairs with Smallest Sums
# Difficulty: Medium | Pattern: Min Heap | Time: O(k log k) | Space: O(k)
import heapq

def k_smallest_pairs(a, b, k):
    if not a or not b: return []
    h = [(a[i] + b[0], i, 0) for i in range(min(len(a), k))]; heapq.heapify(h); res = []
    while h and len(res) < k:
        _, i, j = heapq.heappop(h); res.append([a[i], b[j]])
        if j + 1 < len(b): heapq.heappush(h, (a[i] + b[j+1], i, j + 1))
    return res

assert k_smallest_pairs([1,7,11], [2,4,6], 3) == [[1,2],[1,4],[1,6]]

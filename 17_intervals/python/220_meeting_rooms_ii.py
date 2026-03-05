# LC#253 — Meeting Rooms II
# Difficulty: Medium | Pattern: Min Heap of end times | Time: O(n log n) | Space: O(n)
import heapq

def min_meeting_rooms(v):
    v.sort(); h = []
    for s, e in v:
        if h and h[0] <= s: heapq.heappop(h)
        heapq.heappush(h, e)
    return len(h)

assert min_meeting_rooms([[0,30],[5,10],[15,20]]) == 2 and min_meeting_rooms([[7,10],[2,4]]) == 1

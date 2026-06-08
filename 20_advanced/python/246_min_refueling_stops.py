# LC#871 — Minimum Number of Refueling Stops
# Difficulty: Hard | Pattern: Greedy + Max Heap | Time: O(n log n) | Space: O(n)
import heapq

def min_refuel_stops(target, fuel, stations):
    h = []; stops = i = 0; reach = fuel
    while reach < target:
        while i < len(stations) and stations[i][0] <= reach:
            heapq.heappush(h, -stations[i][1]); i += 1
        if not h: return -1
        reach -= heapq.heappop(h); stops += 1
    return stops

assert min_refuel_stops(100, 10, [[10,60],[20,30],[30,30],[60,40]]) == 2 and min_refuel_stops(100, 1, [[10,100]]) == -1

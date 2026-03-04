# LC#252 — Meeting Rooms
# Difficulty: Easy | Pattern: Sort + adjacent check | Time: O(n log n) | Space: O(1)
def can_attend_meetings(v):
    v.sort()
    return all(v[i][0] >= v[i-1][1] for i in range(1, len(v)))

assert not can_attend_meetings([[0,30],[5,10],[15,20]]) and can_attend_meetings([[7,10],[2,4]])

# LC#759 — Employee Free Time
# Difficulty: Hard | Pattern: Merge intervals | Time: O(n log n) | Space: O(n)
def employee_free_time(schedule):
    all_iv = sorted(x for e in schedule for x in e); res = []; end = all_iv[0][1]
    for s, e in all_iv:
        if s > end: res.append([end, s])
        end = max(end, e)
    return res

assert employee_free_time([[[1,2],[5,6]],[[1,3]],[[4,10]]]) == [[3,4]]

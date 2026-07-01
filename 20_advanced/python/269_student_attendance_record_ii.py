# LC#552 — Student Attendance Record II
# Difficulty: Hard | Pattern: DP over (absences, late streak) | Time: O(n) | Space: O(1)
def check_record(n):
    M = 10**9 + 7; dp = {(0, 0): 1}
    for _ in range(n):
        nd = {}
        for (a, l), v in dp.items():
            for key in ((a, 0), (a + 1, 0) if a == 0 else None, (a, l + 1) if l < 2 else None):
                if key: nd[key] = (nd.get(key, 0) + v) % M
        dp = nd
    return sum(dp.values()) % M

assert check_record(2) == 8 and check_record(1) == 3 and check_record(10101) == 183236316

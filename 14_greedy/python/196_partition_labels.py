# LC#763 — Partition Labels
# Difficulty: Medium | Pattern: Greedy last occurrence | Time: O(n) | Space: O(1)
def partition_labels(s):
    last = {c: i for i, c in enumerate(s)}; res = []; start = end = 0
    for i, c in enumerate(s):
        end = max(end, last[c])
        if i == end: res.append(end - start + 1); start = i + 1
    return res

assert partition_labels("ababcbacadefegdehijhklij") == [9, 7, 8]

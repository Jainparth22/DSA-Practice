# LC#493 — Reverse Pairs
# Difficulty: Hard | Pattern: Merge Sort count | Time: O(n log n) | Space: O(n)
def reverse_pairs(a):
    def sort_count(arr):
        if len(arr) <= 1: return arr, 0
        m = len(arr) // 2
        l, cl = sort_count(arr[:m]); r, cr = sort_count(arr[m:]); cnt = cl + cr; j = 0
        for x in l:
            while j < len(r) and x > 2 * r[j]: j += 1
            cnt += j
        return sorted(l + r), cnt
    return sort_count(a)[1]

assert reverse_pairs([1,3,2,3,1]) == 2 and reverse_pairs([2,4,3,5,1]) == 3

# LC#1569 — Number of Ways to Reorder Array with Same BST
# Difficulty: Hard | Pattern: Combinatorics + recursion | Time: O(n^2) | Space: O(n^2)
from math import comb

def num_of_ways(nums):
    M = 10**9 + 7
    def f(a):
        if len(a) <= 2: return 1
        l = [x for x in a[1:] if x < a[0]]; r = [x for x in a[1:] if x > a[0]]
        return comb(len(a) - 1, len(l)) * f(l) * f(r) % M
    return (f(nums) - 1) % M

assert num_of_ways([2,1,3]) == 1 and num_of_ways([3,4,5,1,2]) == 5 and num_of_ways([1,2,3]) == 0

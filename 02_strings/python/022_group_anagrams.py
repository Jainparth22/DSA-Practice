# LC#49 — Group Anagrams
# Difficulty: Medium
# Pattern: Hash Map + Sorting
# Time: O(n * k log k) | Space: O(n*k)
#
# Approach:
#   Sort each string to get a canonical key.
#   Use defaultdict to group strings by their sorted key.

from collections import defaultdict


class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        groups = defaultdict(list)
        for s in strs:
            key = "".join(sorted(s))
            groups[key].append(s)
        return list(groups.values())


if __name__ == "__main__":
    s = Solution()
    res1 = s.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"])
    assert len(res1) == 3

    res2 = s.groupAnagrams([""])
    assert len(res2) == 1

    res3 = s.groupAnagrams(["a"])
    assert len(res3) == 1

    print("All tests passed!")

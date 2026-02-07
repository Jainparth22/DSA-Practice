# LC#202 — Happy Number
# Difficulty: Easy | Pattern: Hash Set
# Time: O(log n) | Space: O(log n)

class Solution:
    def isHappy(self, n: int) -> bool:
        seen = set()
        while n != 1:
            if n in seen:
                return False
            seen.add(n)
            n = sum(int(d) ** 2 for d in str(n))
        return True

if __name__ == "__main__":
    s = Solution()
    assert s.isHappy(19) == True
    assert s.isHappy(2) == False
    assert s.isHappy(1) == True
    assert s.isHappy(7) == True
    print("All tests passed!")

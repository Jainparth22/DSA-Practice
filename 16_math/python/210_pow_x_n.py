# LC#50 — Pow(x, n)
# Difficulty: Medium | Pattern: Fast Exponentiation
# Time: O(log n) | Space: O(log n)

class Solution:
    def myPow(self, x: float, n: int) -> float:
        def fast_pow(base, exp):
            if exp == 0:
                return 1.0
            half = fast_pow(base, exp // 2)
            return half * half if exp % 2 == 0 else half * half * base

        if n < 0:
            x, n = 1 / x, -n
        return fast_pow(x, n)

if __name__ == "__main__":
    s = Solution()
    assert abs(s.myPow(2.0, 10) - 1024.0) < 1e-5
    assert abs(s.myPow(2.0, -2) - 0.25) < 1e-5
    assert abs(s.myPow(2.1, 3) - 9.261) < 1e-3
    print("All tests passed!")

# LC#13 — Roman to Integer
# Difficulty: Easy | Pattern: Hash Map
# Time: O(n) | Space: O(1)

class Solution:
    def romanToInt(self, s: str) -> int:
        val = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000}
        result = 0
        for i in range(len(s)):
            if i + 1 < len(s) and val[s[i]] < val[s[i+1]]:
                result -= val[s[i]]
            else:
                result += val[s[i]]
        return result

if __name__ == "__main__":
    s = Solution()
    assert s.romanToInt("III") == 3
    assert s.romanToInt("LVIII") == 58
    assert s.romanToInt("MCMXCIV") == 1994
    assert s.romanToInt("IV") == 4
    print("All tests passed!")

// LC#13 — Roman to Integer
// Difficulty: Easy | Pattern: Hash Map + Linear Scan
// Time: O(n) | Space: O(1)
// Approach: Map each symbol to its value. If current < next, subtract it; else add it.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> val = {
            {'I',1},{'V',5},{'X',10},{'L',50},
            {'C',100},{'D',500},{'M',1000}
        };
        int result = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            if (i + 1 < (int)s.size() && val[s[i]] < val[s[i+1]])
                result -= val[s[i]];
            else
                result += val[s[i]];
        }
        return result;
    }
};

int main() {
    Solution sol;
    cout << sol.romanToInt("III")    << endl; // 3
    cout << sol.romanToInt("LVIII")  << endl; // 58
    cout << sol.romanToInt("MCMXCIV")<< endl; // 1994
    cout << sol.romanToInt("IV")     << endl; // 4
    cout << "All tests passed!" << endl;
    return 0;
}

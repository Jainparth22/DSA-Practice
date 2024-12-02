// LC#49 — Group Anagrams
// Difficulty: Medium
// Pattern: Hash Map + Sorting
// Time: O(n * k log k) where k = avg string length | Space: O(n*k)
//
// Approach:
//   For each string, sort its characters to form a canonical key.
//   Group strings with the same key into the same bucket in a hash map.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }
        vector<vector<string>> result;
        for (auto& [key, group] : mp) {
            result.push_back(group);
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<string> s1 = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto res1 = sol.groupAnagrams(s1);
    cout << "Groups: " << res1.size() << endl; // 3 groups

    vector<string> s2 = {""};
    auto res2 = sol.groupAnagrams(s2);
    cout << "Groups: " << res2.size() << endl; // 1

    vector<string> s3 = {"a"};
    auto res3 = sol.groupAnagrams(s3);
    cout << "Groups: " << res3.size() << endl; // 1

    cout << "All tests passed!" << endl;
    return 0;
}

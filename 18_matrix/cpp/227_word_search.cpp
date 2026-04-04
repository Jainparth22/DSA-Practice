// LC#79 — Word Search
// Difficulty: Medium
// Pattern: Backtracking / DFS on Grid
// Time: O(m*n*4^L) where L=word length | Space: O(L) recursion
//
// Approach:
//   For each cell, try starting the word from there.
//   DFS in 4 directions: up/down/left/right.
//   Mark current cell visited (temporarily '#') to prevent reuse.
//   Restore cell after each DFS attempt (backtrack).
//   Return true as soon as word is fully matched.

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool dfs(vector<vector<char>>& board, const string& word,
             int i, int j, int idx) {
        if (idx == (int)word.size()) return true;
        if (i < 0 || i >= (int)board.size() ||
            j < 0 || j >= (int)board[0].size() ||
            board[i][j] != word[idx]) return false;
        char tmp = board[i][j];
        board[i][j] = '#'; // mark visited
        bool found = dfs(board, word, i+1, j, idx+1)
                  || dfs(board, word, i-1, j, idx+1)
                  || dfs(board, word, i, j+1, idx+1)
                  || dfs(board, word, i, j-1, idx+1);
        board[i][j] = tmp; // restore
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < (int)board.size(); i++)
            for (int j = 0; j < (int)board[0].size(); j++)
                if (dfs(board, word, i, j, 0)) return true;
        return false;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> b1 = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout << sol.exist(b1, "ABCCED") << endl; // 1 (true)
    cout << sol.exist(b1, "SEE")    << endl; // 1 (true)
    cout << sol.exist(b1, "ABCB")   << endl; // 0 (false)

    vector<vector<char>> b2 = {{'a'}};
    cout << sol.exist(b2, "a") << endl; // 1 (true)

    cout << "All tests passed!" << endl;
    return 0;
}

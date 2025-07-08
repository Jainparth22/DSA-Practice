/*
 * LC #207 — Course Schedule
 * Difficulty : Medium
 * Pattern    : Graph — Cycle Detection (Topological Sort / DFS)
 * Time       : O(V + E)
 * Space      : O(V + E)
 *
 * Approach:
 *   Build adjacency list. DFS with 3 states:
 *     0 = unvisited, 1 = in-progress (on current DFS path), 2 = done
 *   If we reach a node with state 1, cycle detected → return false.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> state; // 0=unvisited, 1=in-progress, 2=done
    vector<vector<int>> adj;
    bool hasCycle = false;

    void dfs(int u) {
        if (hasCycle) return;
        state[u] = 1;
        for (int v : adj[u]) {
            if (state[v] == 1) { hasCycle = true; return; }
            if (state[v] == 0) dfs(v);
        }
        state[u] = 2;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adj.assign(numCourses, {});
        state.assign(numCourses, 0);
        for (auto& p : prerequisites) adj[p[1]].push_back(p[0]);
        for (int i = 0; i < numCourses; i++)
            if (state[i] == 0) dfs(i);
        return !hasCycle;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> p1 = {{1,0}}; cout << boolalpha << sol.canFinish(2, p1) << "\n"; // true
    Solution sol2;
    vector<vector<int>> p2 = {{1,0},{0,1}}; cout << sol2.canFinish(2, p2) << "\n"; // false
    return 0;
}

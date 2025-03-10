// LC#735 — Asteroid Collision
// Difficulty: Medium | Pattern: Stack | Time: O(n) | Space: O(n)
#include <bits/stdc++.h>
using namespace std;
vector<int> asteroidCollision(vector<int>& a) {
    vector<int> st;
    for (int x : a) {
        bool alive = true;
        while (alive && x < 0 && !st.empty() && st.back() > 0) {
            if (st.back() < -x) st.pop_back();
            else { if (st.back() == -x) st.pop_back(); alive = false; }
        }
        if (alive) st.push_back(x);
    }
    return st;
}
int main() { vector<int> a = {5,10,-5}; for (int x : asteroidCollision(a)) cout << x << " "; } // 5 10

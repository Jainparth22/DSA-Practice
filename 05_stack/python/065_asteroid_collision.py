# LC#735 — Asteroid Collision
# Difficulty: Medium | Pattern: Stack | Time: O(n) | Space: O(n)
def asteroid_collision(a):
    st = []
    for x in a:
        alive = True
        while alive and x < 0 and st and st[-1] > 0:
            if st[-1] < -x: st.pop()
            else:
                if st[-1] == -x: st.pop()
                alive = False
        if alive: st.append(x)
    return st

assert asteroid_collision([5,10,-5]) == [5, 10] and asteroid_collision([8,-8]) == []

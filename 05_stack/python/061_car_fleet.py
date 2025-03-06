# LC#853 — Car Fleet
# Difficulty: Medium | Pattern: Sort + Stack | Time: O(n log n) | Space: O(n)
def car_fleet(target, pos, speed):
    cars = sorted(zip(pos, speed), reverse=True)
    fleets, cur = 0, 0
    for p, s in cars:
        t = (target - p) / s
        if t > cur: fleets += 1; cur = t
    return fleets

assert car_fleet(12, [10,8,0,5,3], [2,4,1,1,3]) == 3

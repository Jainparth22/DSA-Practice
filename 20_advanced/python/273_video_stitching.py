# LC#1024 — Video Stitching
# Difficulty: Medium | Pattern: Greedy | Time: O(n log n) | Space: O(1)
def video_stitching(clips, t):
    clips.sort(); cnt = end = far = i = 0
    while end < t:
        while i < len(clips) and clips[i][0] <= end: far = max(far, clips[i][1]); i += 1
        if far == end: return -1
        end = far; cnt += 1
    return cnt

assert video_stitching([[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]], 10) == 3 and video_stitching([[0,1],[1,2]], 5) == -1

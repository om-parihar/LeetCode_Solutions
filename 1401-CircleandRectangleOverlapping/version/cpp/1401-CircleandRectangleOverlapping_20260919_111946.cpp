// Last updated: 9/19/2026, 11:19:46 AM
1class Solution {
2public:
3    bool checkOverlap(int radius, int xCenter, int yCenter,
4        int x1, int y1, int x2, int y2) {
5
6        int x = max(x1, min(xCenter, x2));
7        int y = max(y1, min(yCenter, y2));
8
9        int dx = x - xCenter;
10        int dy = y - yCenter;
11
12        if (dx * dx + dy * dy <= radius * radius)
13            return true;
14
15        return false;
16    }
17};
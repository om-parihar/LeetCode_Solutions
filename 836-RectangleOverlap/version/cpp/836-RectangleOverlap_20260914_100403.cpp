// Last updated: 9/14/2026, 10:04:03 AM
1class Solution {
2public:
3    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
4        if(rec1[2] <= rec2[0] || rec2[2] <= rec1[0] ||
5           rec1[3] <= rec2[1] || rec2[3] <= rec1[1])
6            return false;
7        
8        return true;
9    }
10};
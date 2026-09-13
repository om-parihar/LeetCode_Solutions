// Last updated: 9/13/2026, 4:02:05 PM
1class Solution {
2public:
3    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
4        int n = img1.size();
5        vector<pair<int,int>> a, b;
6
7        for(int i = 0; i < n; i++) {
8            for(int j = 0; j < n; j++) {
9                if(img1[i][j]) a.push_back({i, j});
10                if(img2[i][j]) b.push_back({i, j});
11            }
12        }
13
14        map<pair<int,int>, int> mp;
15        int ans = 0;
16
17        for(auto [r1, c1] : a) {
18            for(auto [r2, c2] : b) {
19                int dr = r2 - r1;
20                int dc = c2 - c1;
21
22                mp[{dr, dc}]++;
23                ans = max(ans, mp[{dr, dc}]);
24            }
25        }
26
27        return ans;
28    }
29};
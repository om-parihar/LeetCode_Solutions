// Last updated: 8/5/2026, 12:10:25 AM
1class Solution {
2public:
3    vector<int> findPeakGrid(vector<vector<int>>& mat) {
4
5        int m = mat.size();
6        int n = mat[0].size();
7
8        int low = 0;
9        int high = n - 1;
10
11        while (low <= high) {
12
13            int mid = low + (high - low) / 2;
14            int maxRow = 0;
15            for (int i = 1; i < m; i++) {
16                if (mat[i][mid] > mat[maxRow][mid])
17                    maxRow = i;
18            }
19
20            int left = (mid > 0) ? mat[maxRow][mid - 1] : -1;
21            int right = (mid < n - 1) ? mat[maxRow][mid + 1] : -1;
22            if (mat[maxRow][mid] > left && mat[maxRow][mid] > right)
23                return {maxRow, mid};
24            if (left > mat[maxRow][mid])
25                high = mid - 1;
26            else
27                low = mid + 1;
28        }
29
30        return {-1, -1};
31    }
32};
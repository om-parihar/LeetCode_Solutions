// Last updated: 9/13/2026, 8:18:03 AM
1class Solution {
2public:
3    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
4        vector<vector<int>> temp (n,vector<int>(n));
5        for(int i=0;i<n;i++){
6            for(int j=0;j<n;j++){
7                int newCol = (j-rowShift[i]%n+n)%n;
8                int newRow = (i-colShift[newCol]%n+n)%n;
9                temp[newRow][newCol]=grid[i][j];
10            }
11        }
12        return temp;
13    }
14};
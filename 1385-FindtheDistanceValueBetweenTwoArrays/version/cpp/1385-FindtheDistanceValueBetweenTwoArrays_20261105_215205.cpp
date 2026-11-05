// Last updated: 11/5/2026, 9:52:05 PM
1class Solution {
2public:
3    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
4        int n = arr1.size();
5        int m = arr2.size();
6        int cnt = 0;
7
8        for(int i = 0; i < n; i++) {
9            bool valid = true;
10
11            for(int j = 0; j < m; j++) {
12                if(abs(arr1[i] - arr2[j]) <= d) {
13                    valid = false;
14                    break;
15                }
16            }
17
18            if(valid) cnt++;
19        }
20
21        return cnt;
22    }
23};
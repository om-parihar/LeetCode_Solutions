// Last updated: 9/17/2026, 4:31:29 PM
1class Solution {
2public:
3    int minSumOfLengths(vector<int>& arr, int target) {
4        int n = arr.size();
5
6        vector<int> best(n, INT_MAX);
7
8        int i = 0;
9        int sum = 0;
10        int ans = INT_MAX;
11        int mn = INT_MAX;
12
13        for(int j = 0; j < n; j++) {
14
15            sum += arr[j];
16
17            while(sum > target) {
18                sum -= arr[i];
19                i++;
20            }
21
22            if(sum == target) {
23
24                int len = j - i + 1;
25
26                if(i > 0 && best[i - 1] != INT_MAX) {
27                    ans = min(ans, len + best[i - 1]);
28                }
29
30                mn = min(mn, len);
31            }
32
33            best[j] = mn;
34        }
35
36        return ans == INT_MAX ? -1 : ans;
37    }
38};
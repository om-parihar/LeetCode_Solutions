// Last updated: 11/15/2026, 10:28:59 PM
1class Solution {
2public:
3    int numOfSubarrays(vector<int>& arr) {
4        const int MOD = 1e9 + 7;
5        long long ans = 0;
6        int prefixSum = 0;
7        int evenCount = 1;
8        int oddCount = 0;
9
10        for (int x : arr) {
11            prefixSum += x;
12
13            if (prefixSum % 2 != 0) {
14                ans = (ans + evenCount) % MOD;
15                oddCount++;
16            } else {
17                ans = (ans + oddCount) % MOD;
18                evenCount++;
19            }
20        }
21
22        return ans;
23    }
24};
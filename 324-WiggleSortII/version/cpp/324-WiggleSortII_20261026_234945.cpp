// Last updated: 10/26/2026, 11:49:45 PM
1
2class Solution {
3public:
4    void wiggleSort(vector<int>& nums) {
5        vector<int> arr = nums;
6        sort(arr.begin(), arr.end());
7
8        int n = nums.size();
9        int mid = (n + 1) / 2;
10        int i = mid - 1;
11        int j = n - 1;
12
13        for (int k = 0; k < n; k++) {
14            if (k % 2 == 0) {
15                nums[k] = arr[i--];
16            } else {
17                nums[k] = arr[j--];
18            }
19        }
20    }
21};
22
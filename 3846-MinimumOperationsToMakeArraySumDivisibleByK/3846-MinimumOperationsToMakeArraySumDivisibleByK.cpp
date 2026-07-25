// Last updated: 7/25/2026, 10:56:13 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        long long sum = 0;
        for (int x : nums) sum += x;
        return sum % k;
    }
};
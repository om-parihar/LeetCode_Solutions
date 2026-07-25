// Last updated: 7/25/2026, 11:01:08 PM
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int a=nums[n/2];
        return a;
    }
};
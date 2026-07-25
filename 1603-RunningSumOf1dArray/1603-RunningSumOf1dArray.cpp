// Last updated: 7/25/2026, 10:57:18 PM
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n =nums.size();
        for(int i=1;i<n;i++){
                nums[i]+=nums[i-1];
        }
        return nums;
    }
};
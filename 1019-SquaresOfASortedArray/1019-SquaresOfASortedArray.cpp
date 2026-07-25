// Last updated: 7/25/2026, 10:58:06 PM
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]=abs(nums[i]*nums[i]);
        }
        sort(nums.begin(),nums.end());
        return nums;
    }
};
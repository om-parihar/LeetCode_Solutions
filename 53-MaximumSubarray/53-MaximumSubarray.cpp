// Last updated: 7/25/2026, 11:02:42 PM
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxSum=INT_MIN;
        int currSum=0;
        for(int i=0;i<n;i++){
            currSum+=nums[i];
            maxSum=max(currSum,maxSum);
            if(currSum<0){
                currSum=0;
            }
        }
        return maxSum;
    }
};
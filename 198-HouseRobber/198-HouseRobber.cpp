// Last updated: 7/25/2026, 11:01:00 PM
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        int pre=0;
        int suf=nums[0];
        for(int i=1;i<n;i++){
            int curr=max(nums[i]+pre,suf);
            pre=suf;
            suf=curr;
        }
        return suf;
    }
};
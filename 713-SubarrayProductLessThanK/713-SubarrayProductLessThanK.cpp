// Last updated: 7/25/2026, 10:58:52 PM
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        if(k<=0) return 0;
        int prod=1;
        int ans=0;
        int i=0,j=0;
        while(j<n){
            prod=prod*nums[j];
            while(prod>=k&&i<=j){
                prod/=nums[i];
                i++;
            }
            ans+=j-i+1;
            j++;
        }
        return ans;
    }
};
// Last updated: 7/25/2026, 11:01:21 PM
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];
        for(int i=0;i<n;i++){
            int mul=nums[i];
            ans=max(mul,ans);
            for(int j=i+1;j<n;j++){
                mul=mul*nums[j];
                ans=max(mul,ans);
            }
        }
        return ans;
    }
};
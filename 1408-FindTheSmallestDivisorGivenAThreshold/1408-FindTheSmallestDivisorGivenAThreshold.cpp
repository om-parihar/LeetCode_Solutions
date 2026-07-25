// Last updated: 7/25/2026, 10:57:29 PM
class Solution {
public:
    bool solve(int mid, vector<int> nums, int threshold){
        long long ans=0;
        for(int it:nums){
            ans+=(it+mid-1)/mid;
        }
        if(ans<=threshold) return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int i=1;
        int j=*max_element(nums.begin(),nums.end());
        int ans=0;
        while(i<=j){
            int mid=(i+j)/2;
            if(solve(mid,nums,threshold)){
                ans=mid;
                j=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return ans;
    }
};
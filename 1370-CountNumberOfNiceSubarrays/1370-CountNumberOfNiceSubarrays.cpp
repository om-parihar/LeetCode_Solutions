// Last updated: 7/25/2026, 10:57:32 PM
class Solution {
public:
    int atleast(vector<int>&nums,int k){
        int n=nums.size();
        int start=0,ans=0,cnt=0;
        for(int end=0;end<n;end++){
            if(nums[end]%2!=0){
                cnt++;
            }
            while(cnt>=k){
                ans+=(n-end);
                if(nums[start]%2!=0){
                    cnt--;
                }
                start++;
            }
        }
        return ans;
    }
    
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        ans=atleast(nums,k)-atleast(nums,k+1);
        return ans;
    }
};
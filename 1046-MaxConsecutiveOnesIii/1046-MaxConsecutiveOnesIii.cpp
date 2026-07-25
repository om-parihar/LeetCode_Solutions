// Last updated: 7/25/2026, 10:57:56 PM
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int end=0,start=0,cnt=0,ans=0;
        while(end<n){
            if(nums[end]==0){
                cnt++;
            }
            while(cnt>k){
                if(nums[start]==0){
                    cnt--;
                }
                start++;
            }
            ans=max(ans,end-start+1);
            end++;
        }
        return ans;
    }
};
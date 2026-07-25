// Last updated: 7/25/2026, 10:58:02 PM
class Solution {
public:
    int atleast(vector<int> &nums,int k){
        int n=nums.size();
        int total=0;
        unordered_map<int,int> mp;
        int start=0,end=0;
        while(end<n){
            mp[nums[end]]++;
            while(mp.size()>=k){
                total+=(n-end);
                mp[nums[start]]--;
                if(mp[nums[start]]==0){
                    mp.erase(nums[start]);
                }
                start++;
            }
            end++;
        }
        return total;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        ans=atleast(nums,k)-atleast(nums,(k+1));
        return ans;
    }
};
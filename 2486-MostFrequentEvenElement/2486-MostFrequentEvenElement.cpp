// Last updated: 7/25/2026, 10:56:35 PM
class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        int n=nums.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                mp[nums[i]]++;
            }
        }
        if(mp.empty()){
            return -1;
        }
        int mx=INT_MIN;
        int ans=nums[0];
        for(auto it:mp){
            if(it.second>mx){
                mx=it.second;
                ans=it.first;
            }
        }
        return ans;
    }
};
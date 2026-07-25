// Last updated: 7/25/2026, 10:56:05 PM
class Solution {
public:
    int reverseNum(int x){
    int rev = 0;
    while(x > 0){
        rev = rev * 10 + (x % 10);
        x /= 10;
    }
    return rev;
}

    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i])!=mp.end()){
                ans=min(ans,i-mp[nums[i]]);
            }
            int rev=reverseNum(nums[i]);
            mp[rev]=i;
        }
        if(ans==INT_MAX) return -1;
        return ans;
    }
};
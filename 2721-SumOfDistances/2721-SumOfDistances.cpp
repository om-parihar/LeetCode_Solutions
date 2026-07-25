// Last updated: 7/25/2026, 10:56:30 PM
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n=nums.size();
        vector<long long> ans(n,0);
        unordered_map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        for(auto &[val,idx]:mp){
            int k=idx.size();
            long long total=0;
            for(auto it:idx){
                total+=it;
            }
            long long prefix=0;
            for(int i=0;i<k;i++){
                total-=idx[i];
                ans[idx[i]]+=(long long)idx[i]*i-prefix+total-(long long)idx[i]*(k-1-i);
                prefix+=idx[i];
            }
        }
        return ans;
    }
};
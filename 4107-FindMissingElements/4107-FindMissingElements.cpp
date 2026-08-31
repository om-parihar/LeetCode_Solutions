// Last updated: 8/31/2026, 4:24:44 PM
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mx=*max_element(nums.begin(),nums.end());
        int mn=*min_element(nums.begin(),nums.end());
        vector<int> ans;
        unordered_map<int,int> mp;
        for(auto it : nums) {
            mp[it]=it;
        }
        for(int i=mn;i<=mx;i++){
            if(mp.find(i)==mp.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// Last updated: 8/4/2026, 4:36:27 PM
1class Solution {
2public:
3    vector<int> findMissingElements(vector<int>& nums) {
4        int mx=*max_element(nums.begin(),nums.end());
5        int mn=*min_element(nums.begin(),nums.end());
6        vector<int> ans;
7        unordered_map<int,int> mp;
8        for(auto it : nums) {
9            mp[it]=it;
10        }
11        for(int i=mn;i<=mx;i++){
12            if(mp.find(i)==mp.end()){
13                ans.push_back(i);
14            }
15        }
16        return ans;
17    }
18};
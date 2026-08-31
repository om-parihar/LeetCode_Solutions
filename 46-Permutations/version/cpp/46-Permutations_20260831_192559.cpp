// Last updated: 8/31/2026, 7:25:59 PM
1class Solution {
2public:
3    void perm(vector<int>& nums, vector<int> &temp,  vector<bool> &avail,vector<vector<int>>& ans){
4        if(temp.size() == nums.size()){
5    ans.push_back(temp);
6    return;
7}
8        else{
9            for(int j=0;j<nums.size();j++){
10                if(avail[j]){
11                    if(j > 0 && nums[j] == nums[j-1] && avail[j-1]) continue;
12                    temp.push_back(nums[j]);
13                    avail[j]=false;
14                    perm(nums,temp,avail,ans);
15                    avail[j]=true;
16                    temp.pop_back();
17                }
18            }
19        }
20    }
21    vector<vector<int>> permuteUnique(vector<int>& nums) {
22        int n=nums.size();
23        sort(nums.begin(),nums.end());
24        vector<vector<int>> ans;
25        vector<int> temp;
26        vector<bool> avail(n,1);
27        perm(nums,temp,avail,ans);
28        return ans;
29    }
30};
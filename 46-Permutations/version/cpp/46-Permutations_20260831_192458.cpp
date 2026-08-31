// Last updated: 8/31/2026, 7:24:58 PM
1class Solution {
2public:
3    void perm(vector<int>& nums, vector<int> &temp,  vector<bool> &avail, set<vector<int>>& st, vector<vector<int>>& ans){
4        if(temp.size()==nums.size()){
5            if(!st.count(temp)){
6                st.insert(temp);
7                ans.push_back(temp);
8            }
9        }
10        else{
11            for(int j=0;j<nums.size();j++){
12                if(avail[j]){
13                    if(j > 0 && nums[j] == nums[j-1] && avail[j-1]) continue;
14                    temp.push_back(nums[j]);
15                    avail[j]=false;
16                    perm(nums,temp,avail,st,ans);
17                    avail[j]=true;
18                    temp.pop_back();
19                }
20            }
21        }
22    }
23    vector<vector<int>> permuteUnique(vector<int>& nums) {
24        int n=nums.size();
25        sort(nums.begin(),nums.end());
26        vector<vector<int>> ans;
27        vector<int> temp;
28        vector<bool> avail(n,1);
29        set<vector<int>> st;
30        perm(nums,temp,avail,st,ans);
31        return ans;
32    }
33};
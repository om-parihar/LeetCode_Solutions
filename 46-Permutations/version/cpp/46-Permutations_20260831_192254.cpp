// Last updated: 8/31/2026, 7:22:54 PM
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
13                    temp.push_back(nums[j]);
14                    avail[j]=false;
15                    perm(nums,temp,avail,st,ans);
16                    avail[j]=true;
17                    temp.pop_back();
18                }
19            }
20        }
21    }
22    vector<vector<int>> permuteUnique(vector<int>& nums) {
23        int n=nums.size();
24        vector<vector<int>> ans;
25        vector<int> temp;
26        vector<bool> avail(n,1);
27        set<vector<int>> st;
28        perm(nums,temp,avail,st,ans);
29        return ans;
30    }
31};
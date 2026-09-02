// Last updated: 9/2/2026, 10:06:43 PM
1class Solution {
2public:
3    void count(int i, vector<int> & candidates, int t, vector<int>& temp, vector<vector<int>>& all){
4        if(t==0){
5            all.push_back(temp);
6            return;
7        }
8        if(i<0 || t<0) return;
9        if(candidates[i]<=t){
10            temp.push_back(candidates[i]);
11            count(i,candidates,t-candidates[i],temp,all);
12            temp.pop_back();
13        }
14        count(i-1,candidates,t,temp,all);
15    }
16    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
17        int n=candidates.size();
18        vector<int> temp;
19        vector<vector<int>> all;
20        count(n-1,candidates,target,temp,all);
21        return all;
22    }
23};
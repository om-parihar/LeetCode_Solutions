// Last updated: 9/3/2026, 2:19:20 PM
1class Solution {
2public:
3    void count(int i, vector<int> & candidates, int t, vector<int>& temp, vector<vector<int>>& all){
4        if(t==0){
5            all.push_back(temp);
6            return;
7        }
8        if(t<0) return;
9        for(int a=i;a<candidates.size();a++){
10            if(candidates[a]>t) continue;
11            temp.push_back(candidates[a]);
12            count(a,candidates,t-candidates[a],temp,all);
13            temp.pop_back();
14        }
15    }
16    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
17        int n=candidates.size();
18        vector<int> temp;
19        vector<vector<int>> all;
20        count(0,candidates,target,temp,all);
21        return all;
22    }
23};
24
25class Solution1 {
26public:
27    void count(int i, vector<int> & candidates, int t, vector<int>& temp, vector<vector<int>>& all){
28        if(t==0){
29            all.push_back(temp);
30            return;
31        }
32        if(i<0 || t<0) return;
33        if(candidates[i]<=t){
34            temp.push_back(candidates[i]);
35            count(i,candidates,t-candidates[i],temp,all);
36            temp.pop_back();
37        }
38        count(i-1,candidates,t,temp,all);
39    }
40    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
41        int n=candidates.size();
42        vector<int> temp;
43        vector<vector<int>> all;
44        count(n-1,candidates,target,temp,all);
45        return all;
46    }
47};
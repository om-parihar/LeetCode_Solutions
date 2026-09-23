// Last updated: 9/23/2026, 7:27:05 PM
1class Solution {
2public:
3    vector<int> findOriginalArray(vector<int>& changed) {
4        int n=changed.size();
5        if(n%2!=0) return {};
6        sort(changed.begin(),changed.end());
7        unordered_map<int,int> mp;
8        vector<int> ans;
9        for(int it: changed){
10            mp[it]++;
11        }
12        for(int x: changed){
13            if(mp[x]==0){
14                continue;
15            }
16            if(mp[2*x]==0) return {};
17            ans.push_back(x);
18            mp[x]--;
19            mp[2*x]--;
20        }
21        return ans;
22    }
23};
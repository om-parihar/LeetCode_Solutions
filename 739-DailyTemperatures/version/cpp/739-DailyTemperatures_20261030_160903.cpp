// Last updated: 10/30/2026, 4:09:03 PM
1class Solution {
2public:
3    vector<int> dailyTemperatures(vector<int>& temperatures) {
4        int n=temperatures.size();
5        stack<pair<int,int>> st;
6        vector<int> ans(n,0);
7        for(int i=n-1;i>=0;i--){
8            while(!st.empty() && st.top().first<=temperatures[i]){
9                st.pop();
10            }
11            if(st.empty()){
12                ans[i]=0;
13            }
14            else{
15                ans[i]=st.top().second-i;
16            }
17            st.push({temperatures[i],i});
18        }
19        return ans;
20    }
21};
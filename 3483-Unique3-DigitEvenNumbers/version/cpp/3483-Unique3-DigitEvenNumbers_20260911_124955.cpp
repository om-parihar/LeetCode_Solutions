// Last updated: 9/11/2026, 12:49:55 PM
1class Solution {
2public:
3    void solve(int i, vector<int>& digits, int val, set<int>& st, vector<bool>& vis) {
4        if(i == 3) {
5            if(val % 2 == 0)
6                st.insert(val);
7            return;
8        }
9
10        for(int a = 0; a < digits.size(); a++) {
11            if(vis[a]) continue;
12            if(i == 0 && digits[a] == 0) continue;
13
14            vis[a] = true;
15            val = val * 10 + digits[a];
16
17            solve(i + 1, digits, val, st, vis);
18
19            val /= 10;
20            vis[a] = false;
21        }
22    }
23
24    int totalNumbers(vector<int>& digits) {
25        set<int> st;
26        vector<bool> vis(digits.size(), false);
27
28        solve(0, digits, 0, st, vis);
29
30        return st.size();
31    }
32};
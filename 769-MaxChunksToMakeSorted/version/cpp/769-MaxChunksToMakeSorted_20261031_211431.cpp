// Last updated: 10/31/2026, 9:14:31 PM
1class Solution {
2public:
3    int maxChunksToSorted(vector<int>& arr) {
4        stack<int> st;
5
6        for(int x : arr) {
7            if(st.empty() || x >= st.top()) {
8                st.push(x);
9            }
10            else {
11                int maxi = st.top();
12
13                while(!st.empty() && st.top() > x) {
14                    st.pop();
15                }
16
17                st.push(maxi);
18            }
19        }
20
21        return st.size();
22    }
23};
24
25class Solution1 {
26public:
27    int maxChunksToSorted(vector<int>& arr) {
28        int cnt=0;
29        int maxi=0;
30        for(int i=0;i<arr.size();i++){
31            maxi=max(maxi,arr[i]);
32            if(maxi==i){
33                cnt++;
34            }
35        }
36        return cnt;
37    }
38};
// Last updated: 10/30/2026, 7:17:55 PM
1class Solution1 {
2public:
3    int maxChunksToSorted(vector<int>& arr) {
4        int cnt=0;
5        int n=arr.size();
6        stack<int> st;
7        for(int i=0;i<n;i++){
8            while(!st.empty() && st.top()<arr[i]){
9                st.pop();
10            }
11            if(st.empty()){
12                cnt++;
13            }
14            st.push(arr[i]);
15        }
16        return cnt;
17    }
18};
19
20class Solution {
21public:
22    int maxChunksToSorted(vector<int>& arr) {
23        int cnt=0;
24        int maxi=0;
25        for(int i=0;i<arr.size();i++){
26            maxi=max(maxi,arr[i]);
27            if(maxi==i){
28                cnt++;
29            }
30        }
31        return cnt;
32    }
33};
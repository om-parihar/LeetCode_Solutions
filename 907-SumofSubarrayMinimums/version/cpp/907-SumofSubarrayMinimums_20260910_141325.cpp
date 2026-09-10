// Last updated: 9/10/2026, 2:13:25 PM
1class Solution {
2public:
3    int sumSubarrayMins(vector<int>& arr) {
4        int n = arr.size();
5        long long ans = 0;
6        const int MOD = 1e9 + 7;
7
8        vector<int> left(n), right(n);
9        stack<int> st;
10
11        for (int i = 0; i < n; i++) {
12            while (!st.empty() && arr[st.top()] > arr[i]) {
13                st.pop();
14            }
15
16            if (st.empty())
17                left[i] = i + 1;
18            else
19                left[i] = i - st.top();
20
21            st.push(i);
22        }
23
24        while (!st.empty())
25            st.pop();
26
27        for (int i = n - 1; i >= 0; i--) {
28            while (!st.empty() && arr[st.top()] >= arr[i]) {
29                st.pop();
30            }
31
32            if (st.empty())
33                right[i] = n - i;
34            else
35                right[i] = st.top() - i;
36
37            st.push(i);
38        }
39
40        for (int i = 0; i < n; i++) {
41            ans = (ans + (long long)arr[i] * left[i] * right[i]) % MOD;
42        }
43
44        return ans;
45    }
46};
47
48class Solution1 {
49public:
50    int sumSubarrayMins(vector<int>& arr) {
51        int n=arr.size();
52        int mod=1e9+7;
53        int mn=INT_MAX;
54        long long sum=0;
55        for(int i=0;i<n;i++){
56            mn=arr[i];
57            for(int j=i;j<n;j++){
58                mn=min(mn,arr[j]);
59                sum+=mn;
60            }
61        }
62        return sum%mod;
63    }
64};
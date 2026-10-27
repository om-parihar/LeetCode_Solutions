// Last updated: 10/27/2026, 10:14:57 PM
1class Solution {
2public:
3    void reverse(string &ans){
4        int i=0;
5        int j=ans.size()-1;
6        while(i<=j){
7            swap(ans[i],ans[j]);
8            i++;
9            j--;
10        }
11        int start=0;
12        string x="";
13        while(start<ans.size() && ans[start]=='0'){
14            start++;
15        }
16        while(start<ans.size()){
17            x+=ans[start];
18            start++;
19        }
20        ans=x;
21        if(ans.size()==0){
22            ans="0";
23            return;
24        }
25    }
26    string removeKdigits(string num, int k) {
27        int n=num.size();
28        if(n==k) return "0";
29        stack<int> st;
30        for(int i=0;i<n;i++){
31            int digit=num[i]-'0';
32            if(st.empty()){
33                st.push(digit);
34            }
35            else{
36                while(k && !st.empty() && st.top()>digit){
37                    st.pop();
38                    k--;
39                }
40                st.push(digit);
41            }
42        }
43        while(k && !st.empty()){
44            st.pop();
45            k--;
46        }
47        string ans="";
48        while(!st.empty()){
49            ans+=to_string(st.top());
50            st.pop();
51        }
52        reverse(ans);
53        return ans;
54    }
55};
// Last updated: 10/3/2026, 12:01:38 PM
1class Solution {
2public:
3    int longestValidParentheses(string s) {
4        stack<int> st;
5        st.push(-1);
6        int len=0;
7        int maxlen=0;
8        for(int i=0;i<s.size();i++){
9            if(s[i]=='('){
10                st.push(i);
11            }
12            else{
13                st.pop();
14                if(st.empty()){
15                    st.push(i);
16                } else{
17                    maxlen=max(maxlen,i-st.top());
18                }
19            }
20        }
21        return maxlen;
22    }
23};
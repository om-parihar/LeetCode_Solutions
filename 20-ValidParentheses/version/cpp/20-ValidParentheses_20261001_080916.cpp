// Last updated: 10/1/2026, 8:09:16 AM
1class Solution {
2public:
3    bool isValid(string s) {
4        int n=s.size();
5        stack<char> st;
6        for(int i=0;i<n;i++){
7            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
8                st.push(s[i]);
9            }
10            else{
11                if(st.empty()) return 0;
12                else if(s[i]==')'){
13                    if(st.top()!='('){
14                        return 0;
15                    }
16                    else{
17                        st.pop();
18                    }
19                }
20                else if(s[i]=='}'){
21                    if(st.top()!='{'){
22                        return 0;
23                    }
24                    else{
25                        st.pop();
26                    }
27                }
28                else{
29                    if(st.top()!='['){
30                        return 0;
31                    }
32                    else{
33                        st.pop();
34                    }
35                }
36            }
37        }
38        if(st.empty()){
39            return true;
40        }
41        return false;
42    }
43};
// Last updated: 7/25/2026, 11:03:08 PM
class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return 0;
                else if(s[i]==')'){
                    if(st.top()!='('){
                        return 0;
                    }
                    else{
                        st.pop();
                    }
                }
                else if(s[i]=='}'){
                    if(st.top()!='{'){
                        return 0;
                    }
                    else{
                        st.pop();
                    }
                }
                else{
                    if(st.top()!='['){
                        return 0;
                    }
                    else{
                        st.pop();
                    }
                }
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
    }
};
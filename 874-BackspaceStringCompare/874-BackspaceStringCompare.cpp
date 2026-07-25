// Last updated: 7/25/2026, 10:58:33 PM
class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n=s.size();
        int m=t.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i]=='#'){
                if(st.empty()){
                    continue;
                }
                else{
                    st.pop();
                }
            }
            else if(st.empty()){
                st.push(s[i]);
            }
            else{
                st.push(s[i]);
            }
        }
        stack<char> sp;
        for(int i=0;i<m;i++){
            if(t[i]=='#'){
                if(sp.empty()){
                    continue;
                }
                else{
                    sp.pop();
                }
            }
            else if(sp.empty()){
                sp.push(t[i]);
            }
            else{
                sp.push(t[i]);
            }
        }
        while(!st.empty() && !sp.empty()){
            if(st.top()!=sp.top()){
                return false;
            }
            st.pop();
            sp.pop();
        }
        if(!sp.empty()) return false;
        if(!st.empty()) return false;
        return true;
    } 
};
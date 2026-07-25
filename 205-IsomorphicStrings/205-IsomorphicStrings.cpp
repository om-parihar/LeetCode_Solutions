// Last updated: 7/25/2026, 11:00:52 PM
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> st, ts;
        for(int i = 0; i < s.size(); i++) {
            if(st.count(s[i]) && st[s[i]] != t[i])
                return false;

            if(ts.count(t[i]) && ts[t[i]] != s[i])
                return false;

            st[s[i]] = t[i];
            ts[t[i]] = s[i];
        }
        return true;
    }
};
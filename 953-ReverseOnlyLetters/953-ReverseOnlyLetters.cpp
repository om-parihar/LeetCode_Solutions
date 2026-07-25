// Last updated: 7/25/2026, 10:58:18 PM
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n=s.size();
        vector<char> alp;
        for(int i=0;i<n;i++){
            if((s[i]>=65 && s[i]<91) || (s[i]>=97 && s[i]<123)){
                alp.push_back(s[i]);
            }
        }
        int a=alp.size();
        int j=a-1;
        for(int i=0;i<n;i++){
            if((s[i]>=65 && s[i]<91) || (s[i]>=97 && s[i]<123)){
                swap(s[i],alp[j]);
                j--;
            }
        }
        return s;
    }
};
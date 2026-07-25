// Last updated: 7/25/2026, 10:57:02 PM
class Solution {
public:
    string replaceDigits(string s) {
        int n=s.size();
        if(s.empty()) return "";
        for(int i=1;i<n;i+=2){
            if(isdigit(s[i])){
                int shift=s[i]-'0';
                s[i]=s[i-1]+shift;
            }
        }
        return s;
    }
};
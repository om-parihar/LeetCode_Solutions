// Last updated: 7/30/2026, 12:51:46 PM
class Solution {
public:
    string smallestPalindrome(string s) {
        vector<char> half;
        for(int i=0;i<s.size()/2;i++){
            half.push_back(s[i]);
        }
        sort(half.begin(),half.end());
        string ans="";
        for(int i=0;i<half.size();i++){
            ans+=half[i];
        }
        if(s.size() % 2)
            ans += s[s.size()/2];

        for(int i=half.size()-1;i>=0;i--){
            ans+=half[i];
        }
        return ans;
    }
};
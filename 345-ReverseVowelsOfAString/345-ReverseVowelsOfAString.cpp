// Last updated: 7/25/2026, 11:00:03 PM
class Solution {
public:
    string reverseVowels(string s) {
        if(s.empty()) return s;
        int n=s.size();
        vector<char> vow;
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                vow.push_back(s[i]);
            }
        }
        int a=vow.size()-1;
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                swap(vow[a],s[i]);
                a--;
            }
        }
        return s;
    }
};
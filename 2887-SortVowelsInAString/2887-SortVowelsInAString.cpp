// Last updated: 7/25/2026, 10:56:27 PM
class Solution {
public:
    string sortVowels(string s) {
        int n=s.size();
        vector<char> ans;
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='A' || s[i]=='e' || s[i]=='E' || s[i]=='i' || s[i]=='I' || s[i]=='o' || s[i]=='O' || s[i]=='u' || s[i]=='U'){
                ans.push_back(s[i]);
            }
        }
        sort(ans.begin(),ans.end());
        int a=ans.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(s[i]=='a' || s[i]=='A' || s[i]=='e' || s[i]=='E' || s[i]=='i' || s[i]=='I' || s[i]=='o' || s[i]=='O' || s[i]=='u' || s[i]=='U'){
                swap(s[i],ans[j]);
                j++;
            }
        }
        return s;
    }
};
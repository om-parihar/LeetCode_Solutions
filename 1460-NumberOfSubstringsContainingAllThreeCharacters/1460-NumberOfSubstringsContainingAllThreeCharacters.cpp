// Last updated: 7/25/2026, 10:57:24 PM
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        int start=0,end=0,len=0,cnt=0;
        while(end<n){
            mp[s[end]]++;
            while(mp.size()==3){
                len+=(n-end);
                mp[s[start]]--;
                if(mp[s[start]]==0){
                    mp.erase(s[start]);
                }
                start++;
            }
            end++;
        }
        return len;
    }
};
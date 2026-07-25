// Last updated: 7/25/2026, 11:03:33 PM
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        // unordered_map<char,int> mp;
        vector<int> mp(256,0);
        int start=0,end=0,len=0;
        while(end<n){
            mp[s[end]]++;
            while(mp[s[end]]>1){
                mp[s[start]]--;
                start++;
            }
            len=max(len,end-start+1);
            end++;
        }
        return len;
    }
};
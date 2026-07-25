// Last updated: 7/25/2026, 10:59:38 PM
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int start=0,end=0,ans=0,maxFre=0;
        vector<int> freq(26,0);
        // unordered_map<int,int> freq;
        while(end<n){
            freq[s[end]-'A']++;
            maxFre=max(maxFre,freq[s[end]-'A']);
            while((end-start+1)-maxFre>k){
                freq[s[start]-'A']--;
                start++;
            }
            ans=max(ans,end-start+1);
            end++;
        }
        return ans;
    }
};
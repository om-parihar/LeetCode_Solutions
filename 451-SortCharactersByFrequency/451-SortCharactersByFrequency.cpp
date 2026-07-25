// Last updated: 7/25/2026, 10:59:31 PM
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        sort(s.begin(),s.end(), [&](char a, char b){
            if(mp[a]==mp[b]) return a>b;
            return mp[a]>mp[b];
        });
        return s;
    }
};
// Last updated: 7/25/2026, 10:57:06 PM
class Solution {
public:
    int beautySum(string s) {
        if(!s.size()) return 0;
        int cnt=0;
        for(int i=0;i<s.size();i++){
            vector<int> freq(26,0);
            for(int j=i;j<s.size();j++){
                freq[s[j]-'a']++;
                int mx=0;
                int mn=INT_MAX;
                for(int k=0;k<26;k++){
                    if(freq[k]>0){
                        mx=max(mx,freq[k]);
                        mn=min(mn,freq[k]);
                    }
                }  
            cnt+=abs(mx-mn);
            }
        }
        return cnt;
    }
};
// Last updated: 7/25/2026, 11:02:20 PM
class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        unordered_map<char,int> mp;
        // vector<int>mp(256,0);
        for(int i=0;i<m;i++){
            mp[t[i]]++;
        }
        int start=0,end=0,ans=INT_MAX,index=-1;
        while(end<n){
            mp[s[end]]--;
            if(mp[s[end]]>=0){
                m--;
            }
            while(!m && start<=end){
                if(ans>end-start+1){
                    ans=end-start+1;
                    index=start;
                }
                mp[s[start]]++;
                if(mp[s[start]]>0){
                    m++;
                }
                start++;
            }
            end++;
        }
        if(index==-1){
            return "";
        }
        string a="";
        for(int i=index;i<index+ans;i++){
            a+=s[i];
        }
        return a;
    }
};
// Last updated: 7/25/2026, 10:59:47 PM
class Solution {
public:
    char findTheDifference(string s, string t) {
        int a=s.size();
        int b=t.size();
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        for(int i=0;i<a;i++){
            if(s[i]!=t[i]){
                return t[i];
            }
        }
        return t.back();
    }
};
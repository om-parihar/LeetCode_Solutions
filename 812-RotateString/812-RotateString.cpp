// Last updated: 7/25/2026, 10:58:37 PM
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        int m=goal.size();
        if(n!=m) return false;
        for(int start=0;start<n;start++){
            if(s[start]==goal[0]){
                bool match=true;
                for(int j=0;j<m;j++){
                    if(s[(start+j)%n]!=goal[j]){
                        match=false;
                        break;
                    }
                }
                if(match) return true;
            }
        }
        return false;
    }
};
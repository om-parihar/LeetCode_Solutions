// Last updated: 7/25/2026, 10:56:15 PM
class Solution {
public:
    bool doesAliceWin(string s) {
        int n=s.size();
        int vowel=0;
        int i=0;
        while(i<n){
            s[i]=tolower(s[i]);
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                vowel++;
            }
            i++;
        }
        return vowel>0;
    }
};
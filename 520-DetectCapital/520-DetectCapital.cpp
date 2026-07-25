// Last updated: 7/25/2026, 10:59:18 PM
class Solution {
public:
    bool detectCapitalUse(string word) {
        int flag=0;
        for(int i=0;i<word.size();i++){
            if(word[i]>=65 && word[i]<=90){
                flag++;
            }
        }
        if(flag==0) return true;
        if(flag==1 && (word[0]>=65&&word[0]<=90)) return true;
        if(flag==word.size()) return true;
        return false;
    }
};
// Last updated: 7/25/2026, 10:57:35 PM
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int n=text.size();
        int m=brokenLetters.size();
        bool b=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(text[i]==brokenLetters[j]){
                    b=1;
                    break;
                }
            }
            if(text[i]==' ' || i==text.size()-1){
                if(b!=1){
                    cnt++;
                }
                b=0;
            }
        }
        return cnt;
    }
};
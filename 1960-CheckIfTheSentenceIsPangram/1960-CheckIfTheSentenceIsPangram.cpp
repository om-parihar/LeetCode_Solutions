// Last updated: 7/25/2026, 10:57:00 PM
class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<bool> alpha(26,0);
        for(int i=0;i<sentence.size();i++){
            int index=sentence[i]-'a';
            alpha[index]=1;
        }
        for(int i=0;i<alpha.size();i++){
            if(alpha[i]==0){
                return false;
            }
        }
        return true;
    }
};
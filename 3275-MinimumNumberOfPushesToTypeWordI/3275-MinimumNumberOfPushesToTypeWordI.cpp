// Last updated: 7/30/2026, 12:51:51 PM
class Solution {
public:
    int minimumPushes(string word) {
        if(word.size()<=8) return word.size();
        else if(word.size()<=16){
            int ans=8;
            int left=word.size()-8;
            ans+=left*2;
            return ans;
        }
        else if(word.size()<=24){
            int ans=8*3;
            int left=word.size()-16;
            ans+=left*3;
            return ans;
        }
        else{
            int ans=8*6;
            int left=word.size()-24;
            ans+=left*4;
            return ans;
        }
        return 0;
    }
};
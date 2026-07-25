// Last updated: 7/25/2026, 10:58:28 PM
class Solution {
public:
    int scoreOfParentheses(string s) {
        int score=0,balance=0;
        for(int i=0;i<s.length();i++){
            if (s[i] =='('){
                ++balance;
            } 
            else{
                --balance;
                if(s[i-1]=='('){
                    score+=(1<<balance); 
                }
            }
        }
        return score;
    }
};
// Last updated: 7/25/2026, 11:03:13 PM
class Solution {
public:
    vector<string> ans;
    string path;
    void solve(int idx, string &digits, vector<string> &mapping){
        if(idx==digits.size()){
            ans.push_back(path);
            return;
        }
        string letters=mapping[digits[idx]-'0'];
        for(auto &ch : letters){
            path.push_back(ch);
            solve(idx+1,digits,mapping);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        vector<string> mapping = {
            "",     
            "",     
            "abc",  
            "def",  
            "ghi",  
            "jkl",  
            "mno",  
            "pqrs", 
            "tuv",  
            "wxyz"  
        };
        solve(0,digits,mapping);
        return ans;
    }
};
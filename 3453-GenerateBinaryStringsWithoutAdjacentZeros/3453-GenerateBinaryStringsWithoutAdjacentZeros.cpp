// Last updated: 7/25/2026, 10:56:18 PM
class Solution {
public:
    void help(int n,int idx, vector<string> &ans, string &temp){
        if(idx==n){
            ans.push_back(temp);
            return;
        }
        temp.push_back('1');
        help(n,idx+1,ans,temp);
        temp.pop_back();

        if(temp.empty()||temp.back()!='0'){
            temp.push_back('0');
            help(n,idx+1,ans,temp);
            temp.pop_back();
        }
    }
public:
    vector<string> validStrings(int n) {
        vector<string> ans;
        string temp;
        help(n,0,ans,temp);
        return ans;
    }
};
// Last updated: 7/25/2026, 11:03:27 PM
class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || numRows>=s.size()){
            return s;
        }
        vector<string> ans(numRows);
        int curr=0;
        int dir=1;
        int n=s.size();
        for(int i=0;i<n;i++){
            ans[curr]+=s[i];

            if(curr==0){
                dir=1;
            }
            else if(curr==numRows-1){
                dir=-1;
            }
            curr+=dir;
        }
        string result;
        for(int i=0;i<ans.size();i++){
            result+=ans[i];
        }
        return result;
    }
};
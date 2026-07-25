// Last updated: 7/25/2026, 11:03:17 PM
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        sort(strs.begin(),strs.end());
        int n=strs.size();
        string a=strs[0];
        string b=strs[n-1];
        string ans="";
        int len=min(a.size(),b.size());
        for(int i=0;i<len;i++){
            if(a[i]!=b[i]){
                return ans;
            }
            else{
                ans+=a[i];
            }
        }
        return ans;
    }
};


// class Solution {
// public:
//     string longestCommonPrefix(vector<string>& strs) {
//         int n=strs.size();
//         if(strs.empty()) return "";
//         string ans="";
//         for(int i=0;i<strs[0].size();i++){
//             for(int j=1;j<n;j++){
//                 if(strs[j][i]!=strs[0][i]){
//                     return ans;
//                 }
//             }
//             ans+=strs[0][i];
//         }
//         return ans;
//     }
// };
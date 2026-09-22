// Last updated: 9/22/2026, 4:37:28 PM
1class Solution {
2public:
3    bool isPalindrome(string &a, int i, int j){
4        if(i>=j){
5            return true;
6        }
7        if(a[i]!=a[j]) return false;
8        return isPalindrome(a,i+1,j-1);
9    }
10    void solve(int i, string& s, vector<string>& temp, vector<vector<string>>& ans){
11        if(i==s.size()){
12            ans.push_back(temp);
13            return;
14        }
15        for(int a=i;a<s.size();a++){
16            if(isPalindrome(s,i,a)){
17                temp.push_back(s.substr(i,a-i+1));
18                solve(a+1,s,temp,ans);
19                temp.pop_back();
20            }
21        }
22    }
23
24    vector<vector<string>> partition(string s) {
25        vector<vector<string>> ans;
26        vector<string> temp;
27        solve(0,s,temp,ans);
28        return ans;
29    }
30};
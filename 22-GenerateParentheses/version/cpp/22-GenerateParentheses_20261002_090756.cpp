// Last updated: 10/2/2026, 9:07:56 AM
1class Solution {
2public:
3    void help(int n,int left, int right, vector<string> &ans,string &temp){
4        if(left+right==2*n){
5            ans.push_back(temp);
6            return;
7        }
8        if(left<n){
9            temp.push_back('(');
10            help(n,left+1,right,ans,temp);
11            temp.pop_back();
12        }
13        if(right<left){
14            temp.push_back(')');
15            help(n,left,right+1,ans,temp);
16            temp.pop_back();
17        }
18    }
19public:
20    vector<string> generateParenthesis(int n) {
21        vector<string> ans;
22        string temp;
23        help(n,0,0,ans,temp);
24        return ans;
25    }
26};
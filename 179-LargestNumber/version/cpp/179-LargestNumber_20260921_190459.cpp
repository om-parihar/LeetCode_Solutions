// Last updated: 9/21/2026, 7:04:59 PM
1class Solution {
2public:
3    string largestNumber(vector<int>& nums) {
4        sort(nums.begin(),nums.end(),[](int a, int b){
5            return to_string(a)+to_string(b)>
6                    to_string(b)+to_string(a);
7        });
8        string ans="";
9        for(int x:nums){
10            ans+=to_string(x);
11        }
12        if(ans[0]=='0') return "0";
13        return ans;
14    }
15};
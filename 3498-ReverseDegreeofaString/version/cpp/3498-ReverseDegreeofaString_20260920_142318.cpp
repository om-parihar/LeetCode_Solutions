// Last updated: 9/20/2026, 2:23:18 PM
1class Solution {
2public:
3    int reverseDegree(string s) {
4        int sum=0;
5        unordered_map<char,int> mp;
6        for(int i=26;i>=1;i--){
7            mp[96+i]=27-i;
8        }
9        for(int i=0;i<s.size();i++){
10            sum+=mp[s[i]]*(i+1);
11        }
12        return sum;
13    }
14};